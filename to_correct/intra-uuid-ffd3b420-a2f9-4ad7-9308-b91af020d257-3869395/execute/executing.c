/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:18:01 by afulmini          #+#    #+#             */
/*   Updated: 2022/03/01 11:38:36 by afulmini         ###   ########.fr       */
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
		return ;
	if (cmd->pid == -1)
		cmd->pid = fork();
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
	else if (execve(path, cmd->args, shell->env) == -1)
		put_error("minishell", "execve error.", strerror(errno));
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
