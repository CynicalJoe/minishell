/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:09:08 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/24 13:47:57 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*temp_file_gen(void)
{
	int i;
	char *name;

	i = 0;
	while(i <= INT_MAX)
	{
		name = ft_itoa(i);
		if (!name)
			return (NULL);
		if (access(name,F_OK) != 0)
			break;
		free(name);
		if (i == INT_MAX)
			return (NULL);
		i++;
	}
	return (name);
}

// prompt to catch the keyword to 
void	catching(char *keyword, int file_fd)
{
	char	*line;

	signal(SIGINT, NULL);
	while (1)
	{
		line = readline("$> ");
		if (line == NULL || ft_strcmp(line, keyword) == 0)
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, file_fd);	// fd of the process
		free(line);
	}
	exit (0);
}

// launch process to wait for the keyword (treat it like a file?)
bool	read_to_keyword(char *keyword, t_redir fds)
{
	pid_t	pid;
	int		file_fd;
	int		status;

	// generate a file for the buffer input of the double input redir <-- repris le principe 
	file_fd = open(fds.temp_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (file_fd == -1)
		return (put_error("minishell", "file", "cannot be opened."));
	// create child process
	pid = fork();
	if (pid == -1)
		return (put_error("minishell", "fork error", strerror(errno)));
	else if (pid == 0)	// caught child process --> launch prompt
		catching(keyword, file_fd);
	else
	{
		// wait for signals from the process
		waitpid(pid, &status, 0);
		if (WIFSIGNALED(status) && WTERMSIG(status) == 2)
			return (FALSE);
		close(file_fd);
	}
	return (TRUE);
}

int	output_redir_mode(char *redirection)
{
	if (ft_strcmp(redirection, ">>") == 0)
		return (O_APPEND);
	else if (ft_strcmp(redirection, ">") == 0)
		return (O_TRUNC);
	return (0);
}

// dispatch all the redir 
bool	dispatch_redir(t_cmd *cmd, size_t arg_i)
{
	if (arg_i >= cmd->size)
		return (put_error("minishell", "syntax error", "error parsing."));
	if (ft_strcmp(cmd->tokens[arg_i - 1], ">>") == 0 || ft_strcmp(cmd->tokens[arg_i - 1], ">") == 0)
		return (file_redir(&cmd->out, cmd->tokens[arg_i], O_WRONLY | O_CREAT | output_redir_mode(cmd->tokens[arg_i - 1]),
				STDOUT_FILENO));
	else if (ft_strcmp(cmd->tokens[arg_i - 1], "<<") == 0)
	{
		cmd->in.temp_file = temp_file_gen();
		//if (double_redir(cmd->in, cmd->tokens[arg_i]) == 0)
		//	return (TRUE);
		if (!read_to_keyword(cmd->tokens[arg_i], cmd->in))
			return (FALSE);
		// "filename" buffer created --> check for a rename process
		return (file_redir(&cmd->in, cmd->in.temp_file, O_RDONLY, STDIN_FILENO));	//  leaves trailing file in the working directory
	}
	else if (ft_strcmp(cmd->tokens[arg_i - 1], "<") == 0)
		return (file_redir(&cmd->in, cmd->tokens[arg_i], O_RDONLY, STDIN_FILENO));
	return (FALSE);
}
