/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:09:08 by afulmini          #+#    #+#             */
/*   Updated: 2022/03/03 20:02:05 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
		ft_putendl_fd(line, file_fd);
		free(line);
	}
	exit (0);
}

bool	read_to_keyword(t_shell *shell, char *keyword, t_cmd *fds)
{
	pid_t	pid;
	int		file_fd;
	int		status;

	signal(SIGQUIT, SIG_IGN);
	file_fd = open(fds->temp_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (file_fd == -1)
		return (put_error("minishell", "file", "cannot be opened."));
	pid = fork();
	if (pid == -1)
		return (put_error("minishell", "fork error", strerror(errno)));
	else if (pid == 0)
		catching(keyword, file_fd);
	else
	{
		waitpid(pid, &status, 0);
		if (WIFSIGNALED(status) && WTERMSIG(status) == 2)
		{
			shell->exit_status = 1;
			return (FALSE);
		}
		close(file_fd);
	}
	return (TRUE);
}

bool	read_while_redir(t_shell *shell, t_cmd *cmd, size_t *arg_i)
{
	bool	is_redir;
	int		i;

	i = 0;
	is_redir = TRUE;
	while (is_redir == TRUE)
	{
		if (!read_to_keyword(shell, cmd->tokens[*arg_i + i], cmd))
		{
			unlink(cmd->temp_file);
			free(cmd->temp_file);
			return (FALSE);
		}
		*arg_i = *arg_i + 1;
		if (ft_strcmp(cmd->tokens[*arg_i + i], "<<") != 0)
			is_redir = FALSE;
		i++;
	}
	*arg_i = *arg_i + i - 1;
	return (TRUE);
}

bool	dispatch_redir(t_shell *shell, t_cmd *cmd, size_t *arg_i)
{
	if (*arg_i >= cmd->size)
		return (put_error("minishell", "syntax error", "error parsing."));
	if (ft_strcmp(cmd->tokens[*arg_i - 1], ">>") == 0
		|| ft_strcmp(cmd->tokens[*arg_i - 1], ">") == 0)
	{
		if (ft_strcmp(cmd->tokens[*arg_i - 1], ">>") == 0)
			shell->double_out = TRUE;
		return (file_redir(cmd, cmd->tokens[*arg_i],
				O_WRONLY | O_CREAT
				| output_redir_mode(cmd->tokens[*arg_i - 1]), 1));
	}
	else if (ft_strcmp(cmd->tokens[*arg_i - 1], "<<") == 0)
	{
		cmd->temp_file = temp_file_gen();
		if (!read_while_redir(shell, cmd, arg_i))
			return (FALSE);
		return (file_redir(cmd, cmd->temp_file,
				O_RDONLY, 0));
	}
	else if (ft_strcmp(cmd->tokens[*arg_i - 1], "<") == 0)
		return (file_redir(cmd, cmd->tokens[*arg_i],
				O_RDONLY, 0));
	return (FALSE);
}
