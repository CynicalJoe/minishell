/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:51:35 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/15 21:46:43 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	execute_program(t_shell *shell, char *path, t_cmd *cmd)
{
	int	status;

	if (path == NULL)
	{
		put_error("minishell", "command not found.", cmd->args[0]);
		shell->exit_status = 127;
		return ;
	}
	if (cmd->pid == -1)
		cmd->pid = fork();
	if (cmd->pid == -1)
		put_error("minishell", "fork error", strerror(errno));
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
