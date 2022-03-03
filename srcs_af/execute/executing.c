/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:18:01 by afulmini          #+#    #+#             */
/*   Updated: 2022/03/03 21:17:58 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	dup_handler(t_cmd *cmd)
{
	if (cmd->in != -1)
	{
		printf(" in handler fd = %d\n", cmd->in);
		dup2(cmd->in, STDIN_FILENO); // fermer standard input pour remplacer avec le fd de source si doit
		//close(cmd->in);
	}
	if (cmd->out != -1)		// pas de else if car il doit pouvoir faire les deux si nécessaire
	{
		printf(" out handler fd = %d\n", cmd->out);
		dup2(cmd->out, STDOUT_FILENO); // la même ici pour l'output
		//close(cmd->out);
	}
}

void	close_fd(t_cmd *cmd)
{
	if (cmd->in != -1)
		close(cmd->in);
	if (cmd->out != -1)
		close(cmd->out);
}

void	execute_program(t_shell *shell, char *path, t_cmd *cmd)
{
	check_exec(shell, cmd, path);
	printf("hello\n");
	if (cmd->pid == -1)
		cmd->pid = fork();
/* 	if (cmd->pid >= 0 && shell->double_out == TRUE && cmd->in != -1)
	{	
		dup2(cmd->in, STDIN_FILENO);
	} */
	if (cmd->pid == -1)
		put_error("minishell", "fork error.", strerror(errno));
	else if (cmd->pid > 0 && !cmd->piped)
		waiting(shell, cmd);
	else if (cmd->pid == 0)
	{
		printf("last fd = %d\n", cmd->in);
		dup_handler(cmd);
		execve(path, cmd->args, shell->env);
		
		close_fd(cmd);
		return ;
	}
	printf("close\n");
	close_fd(cmd);
	
}

void	execute_command(t_shell *shell, t_cmd *cmd)
{
	char	*program;
	char	*program_path;

	if (cmd->args == NULL)
		return ;
	program = ft_str_tolower(cmd->args[0]);
	if (get_builtin(program) != NULL)
	{
		cmd->pid = fork();
		if (cmd->pid == 0)
		{
			dup_handler(cmd);
			get_builtin(program)(shell, cmd->args);
			printf("get pid = %d\n",getpid());
			//kill(cmd->pid, SIGTERM);
			exit(shell->exit_status);
		}
		wait(NULL);
	}
	else if (ft_contains_char(program, '/'))
	{
		if (check_if_exist(NULL, program) != FALSE)
			execute_program(shell, program, cmd);
		else
			put_error("minishell", "no such file or directory.", cmd->args[0]);
	}
	else
	{
		program_path = get_program_path(shell, cmd->args[0]);
		execute_program(shell, program_path, cmd);
		free(program_path);
	}
}
