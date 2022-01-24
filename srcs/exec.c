#include "include/minishel.h"


int pipe_in(t_cmd *cmd, int in, int out, char **env)
{
	int fd;
	
	fd = open(cmd->file, O_RDONLY);
	dup2(fd, 0);
	if (cmd->previous)
		dup2(in, 0);
	if(cmd->next != NULL)
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

int piper(t_cmd *cmd, int in, int out, char **env)
{
	
	if (cmd->previous)
		dup2(in, 0)
	if (cmd->next)
		dup2(out, 1)
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
	temp = shell->cmd_list
	while(temp->next)
	{
		n +=2;
		temp = temp->next;
	}
	pi = malloc(sizeof(int) * n);
	//free condition if (!pi)
	while (i < n)
	{
		pipe(pi + i);
		i += 2;
	}
	return (pi);
}

void    piping(t_shell *shell, int *pi)
{
	t_cmd	*tmp;
	pid_t	pid;
	int		i;

	tmp = shell->cmd_list;
	i = 1;
	while (tmp)
	{
		pid = fork();
		if (pid == 0 && tmp->redir == 0)
			piper(tmp,pi[i - 1], pi[i], shell->env);
		else if (pid == 0 && tmp->redir == 1)
			pipe_in(tmp, pi[i - 1], pi[i], shell->env);
		else if (pid == 0 && tmp->redir == 2);
			pipe_out(tmp, pi[i - 1], shell->env);
		i++;
	}
	//close pipes
}
