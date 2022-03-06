/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 19:03:22 by afulmini          #+#    #+#             */
/*   Updated: 2022/03/04 20:13:06 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	start_pipe_redir(t_cmd *cmd)
{
	if (cmd->previous != NULL && cmd->previous->piped)
		if (cmd->in == -1)
			dup2(cmd->previous->pipe[0], 0);
	if (cmd->next != NULL && cmd->piped)
		if (cmd->out == -1)
			dup2(cmd->pipe[1], 1);
	if (cmd->piped)
	{
		close(cmd->pipe[0]);
		close(cmd->pipe[1]);
	}
}

void	close_pipes(t_cmd *cmd)
{
	close(cmd->pipe[1]);
	if (cmd->piped && cmd->next == NULL)
		close(cmd->pipe[0]);
}

void	wait_pipes(t_shell *shell, t_cmd *cmd)
{
	t_cmd	*current;
	int		status;

	current = cmd;
	while (current != NULL && (current->piped
			|| current->previous->piped) && current->pid != -1)
	{
		waitpid(current->pid, &status, 0);
		current = current->next;
		if (!(current != NULL && (current->piped
					|| current->previous->piped) && current->pid != -1))
		{
			if (WIFEXITED(status))
				shell->exit_status = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				shell->exit_status = 128 + WTERMSIG(status);
		}
	}
}

void	parse_execute_pipe(t_shell *shell, t_cmd *cmd)
{
	parse_cmd(shell, cmd);
	start_pipe_redir(cmd);
	execute_command(shell, cmd);
	exit(EXIT_SUCCESS);
}

t_cmd	*process_piped(t_shell *shell, t_cmd *cmd)
{
	t_cmd	*current;

	current = cmd;
	while (current != NULL && (current->piped || current->previous->piped))
	{
		if (current->piped)
			if (pipe(current->pipe) == -1)
				break ;
		current->pipe_pid = fork();
		if (current->pipe_pid == -1)
			put_error("minishell", "fork error", strerror(errno));
		else if (current->pipe_pid == 0)
			parse_execute_pipe(shell, current);
		wait(NULL);
		if (current->piped)
			close_pipes(current);
		if (current->piped && current->next == NULL)
			put_error("Ambiguous", "Piping", "Behaviour not defined");
		current = current->next;
	}
	wait_pipes(shell, cmd);
	return (current);
}
