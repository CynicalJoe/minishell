#include "../include/minishell.h"

void stat_pipe_redir(t_cmd *cmd)
{
	if (cmd->previous != NULL && cmd->previous->piped)
		if (cmd->in.fd_backup == -1)
			dup2(cmd->previous->pipe[0], 0);
	if (cmd->next != NULL && cmd->piped)
		if (cmd->out.fd_backup == -1)
			dup2(cmd->pipe[1], 1);
}

t_cmd *process_piped(t_shell *shell, t_cmd *cmd)
{
	t_cmd *current;
	pid_t pid;
	int pipe_fd[2];

	current = cmd;
	while (current != NULL && (current->piped || current->previous->piped))
	{
		if (current->piped)
			if (pipe(pipe_fd) == -1)
				break ;
		pid = fork();
		if (pid == -1)
			put_error("minishell", "fork error", strerror(errno));
		else if (pid == 0)
		{
			parse_cmd(shell, current);
			start_pipe_redir(current);
		}
		if (current->piped)
			// close_pipes(current);
			current = current->next;
	}
}

int pipe_in(t_cmd *cmd, int in, int out, char **env)
{
	int fd;

	fd = open(cmd->file, O_RDONLY);
	dup2(fd, 0);
	if (cmd->previous)
		dup2(in, 0);
	if (cmd->next != NULL)
		dup2(out, 1);
	execve(cmd->args[0], cmd->args, env);
	close(fd);
	return (1);
}

int pipe_out(t_cmd *cmd, int in, char **env)
{
	int fd;

	fd = open(cmd->file, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (cmd->previous != NULL)
		dup2(in, 0);
	dup2(fd, 1);
	execve(cmd->args[0], cmd->args, env);
	return (1);
}

void piping(t_shell *shell, int *pi, t_cmd *cmd)
{
	t_cmd *tmp;
	pid_t pid;
	int i;

	tmp = shell->cmd_list;
	i = 1;
	while (tmp)
	{
		pid = fork();
		if (pid == 0 && tmp->redir == 0)
			piper(tmp, pi[i - 1], pi[i], shell->env);
		else if (pid == 0 && tmp->redir == 1)
			pipe_in(tmp, pi[i - 1], pi[i], shell->env);
		else if (pid == 0 && tmp->redir == 2)
			;
		pipe_out(tmp, pi[i - 1], shell->env);
		i++;
	}
	// close pipes
}

int piper(t_cmd *cmd, int in, int out, char **env)
{

	if (cmd->previous)
		dup2(in, 0);
	if (cmd->next)
		dup2(out, 1);
	execve(cmd->args[0], cmd->args, env);
	return (1);
}

int *create_pipes(t_shell *shell)
{
	int *pi;
	int n;
	int i;
	t_cmd *temp;

	n = 0;
	i = 0;
	temp = shell->cmd_list;
	while (temp->next)
	{
		n += 2;
		temp = temp->next;
	}
	pi = malloc(sizeof(int) * n);
	// free condition if (!pi)
	while (i < n)
	{
		pipe(pi + i);
		i += 2;
	}
	return (pi);
}
