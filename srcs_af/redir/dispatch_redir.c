/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:09:08 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/24 12:45:33 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
bool	read_to_keyword(char *keyword)
{
	pid_t	pid;
	int		file_fd;
	int		status;

	// generate a file for the buffer input of the double input redir <-- repris le principe 
	file_fd = open("filename", O_WRONLY | O_CREAT | O_TRUNC, 0666);
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
		if (double_redir(cmd->in, cmd->tokens[arg_i]) == 0)
			return (TRUE);
		/* if (!read_to_keyword(cmd->tokens[arg_i]))
			return (FALSE); */
		// "filename" buffer created --> check for a rename process
		//return (file_redir(&cmd->in, "filename", O_RDONLY, STDIN_FILENO));	//  leaves trailing file in the working directory
	}
	else if (ft_strcmp(cmd->tokens[arg_i - 1], "<") == 0)
		return (file_redir(&cmd->in, cmd->tokens[arg_i], O_RDONLY, STDIN_FILENO));
	return (FALSE);
}
