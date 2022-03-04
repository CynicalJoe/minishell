/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:18:01 by afulmini          #+#    #+#             */
/*   Updated: 2022/03/04 10:30:55 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	dup_handler(t_cmd *cmd)
{
	if (cmd->in != -1)
		dup2(cmd->in, STDIN_FILENO);
	if (cmd->out != -1)
		dup2(cmd->out, STDOUT_FILENO);
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
	if (!check_exec(shell, cmd, path))
		return ;
	if (cmd->pid == -1)
		cmd->pid = fork();
	if (cmd->pid == -1)
		put_error("minishell", "fork error.", strerror(errno));
	else if (cmd->pid > 0 && !cmd->piped)
		waiting(shell, cmd);
	else if (cmd->pid == 0)
	{
		dup_handler(cmd);
		execve(path, cmd->args, shell->env);
		close_fd(cmd);
		return ;
	}
	close_fd(cmd);
}

void	not_builtin(t_shell *shell, char *program, t_cmd *cmd)
{
	if (ft_contains_char(program, '/'))
	{
		if (check_if_exist(NULL, program) != FALSE)
			execute_program(shell, program, cmd);
		else
			put_error("minishell", "no such file or directory.", cmd->args[0]);
	}
	else
	{
		program = get_program_path(shell, cmd->args[0]);
		execute_program(shell, program, cmd);
		free(program);
	}
}

void	execute_command(t_shell *shell, t_cmd *cmd)
{
	char	*program;

	if (cmd->args == NULL)
		return ;
	program = ft_str_tolower(cmd->args[0]);
	if (get_builtin(program) != NULL)
	{
		if (cmd->in != -1 || cmd->out != -1)
		{
			cmd->pid = fork();
			if (cmd->pid == 0)
			{
				dup_handler(cmd);
				get_builtin(program)(shell, cmd->args);
				exit(shell->exit_status);
			}
		}
		else
			get_builtin(program)(shell, cmd->args);
		wait(NULL);
	}
	else if (get_builtin(program) == NULL)
		not_builtin(shell, program, cmd);
}
