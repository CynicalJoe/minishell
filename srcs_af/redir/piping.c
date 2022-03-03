#include "../include/minishell.h"

void	start_pipe_redir(t_cmd *cmd)
{
	if (cmd->previous != NULL && cmd->previous->piped)
		if (cmd->in.fd == -1)
			dup2(cmd->previous->pipe[0], 0);
	if (cmd->next != NULL && cmd->piped)
		if (cmd->out.fd == -1)
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

t_cmd	*process_piped(t_shell *shell, t_cmd *cmd)
{
	t_cmd	*current;

	current = cmd;
	while (current != NULL && (current->piped || current->previous->piped))
	{
		if (current->piped)
			if (pipe(current->pipe) == -1)
				break ;
		current->pid = fork();
		if (current->pid == -1)
			put_error("minishell", "fork error", strerror(errno));
		else if (current->pid == 0)
		{
			parse_cmd(shell, current);
			start_pipe_redir(current);
			execute_command(shell, current);
			exit(EXIT_SUCCESS);
		}
		if (current->piped)
			close_pipes(current);
		if (current->piped && current->next == NULL)
			put_error("Ambiguous", "Piping", "Behaviour not defined");
		current = current->next;
	}
	wait_pipes(shell, cmd);
	return (current);
}
