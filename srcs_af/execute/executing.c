/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:18:01 by afulmini          #+#    #+#             */
/*   Updated: 2022/03/03 16:28:07 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_str_tolower(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		s[i] = (char)ft_tolower(s[i]);
		i++;
	}
	return (s);
}

void	dup_handler(t_cmd *cmd)
{
	
	if (cmd->in.fd != -1)
	{
		dup2(STDIN_FILENO, cmd->in.fd); // fermer standard input pour remplacer avec le fd de source si doit
		close(STDIN_FILENO);
	}
	if (cmd->out.fd != -1)		// pas de else if car il doit pouvoir faire les deux si nécessaire
	{
		printf("hi\n");
		dup2(STDOUT_FILENO, cmd->out.fd); // la même ici pour l'output
		close(STDOUT_FILENO);
	}
}

void	close_fd(t_cmd *cmd)
{
	if (cmd->in.fd != -1)
		close(cmd->in.fd);
	if (cmd->out.fd != -1)
		close(cmd->out.fd);
}

void	execute_program(t_shell *shell, char *path, t_cmd *cmd)
{
	int	status;

	if (path == NULL)
	{
		put_error("minishell", "command not found.", cmd->args[0]);
		shell->exit_status = 127;
		return ;
	}
	if (ft_strncmp(cmd->args[0], "./", 2) == 0
		|| ft_strncmp(cmd->args[0], "../", 3) == 0)
	{
		put_error("minishell", "no such file or directory.", cmd->args[0]);
		shell->exit_status = 126;
		return ;
	}
	if (cmd->pid == -1)
		cmd->pid = fork();
	if (cmd->pid >= 0 && shell->double_out == TRUE && cmd->in.fd != -1)
	{	
		dup2(cmd->in.fd, STDIN_FILENO);
		close(cmd->in.fd);
	}
	if (cmd->pid == -1)
		put_error("minishell", "fork error.", strerror(errno));
	else if (cmd->pid > 0 && !cmd->piped)
	{
		waitpid(cmd->pid, &status, 0);
		if (WIFEXITED(status))
			shell->exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			shell->exit_status = 128 + WTERMSIG(status);
	}
	else if (cmd->pid == 0)
	{
		printf("fd = %d\n",cmd->in.fd );
		dup_handler(cmd);
		execve(path, cmd->args, shell->env);
		close_fd(cmd);
		return ;
	}
	close(cmd->in.fd);
}

void	execute_command(t_shell *shell, t_cmd *cmd)
{
	char	*program;
	char	*program_path;

	if (cmd->args == NULL)
		return ;
	program = ft_str_tolower(cmd->args[0]);
	if (get_builtin(program) != NULL)
		get_builtin(program)(shell, cmd->args);
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
