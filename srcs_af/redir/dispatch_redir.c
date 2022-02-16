/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:09:08 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/16 14:53:45 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	get_output_redirection_mode(char *redirection)
{
	if (ft_strcmp(redirection, ">>") == 0)
		return (O_APPEND);
	else if (ft_strcmp(redirection, ">") == 0)
		return (O_TRUNC);
	return (0);
}

bool	dispatch_redir(t_cmd *cmd, size_t arg_i)
{
	if (arg_i >= cmd->size)
		return (put_error("minishell", "syntax error", "redir parsing."));
	if (ft_strcmp(cmd->tokens[arg_i - 1], ">>") == 0 || ft_strcmp(cmd->tokens[arg_i - 1], ">") == 0)
		return (file_redir(&cmd->out, cmd->tokens[arg_i], O_WRONLY | O_CREAT | get_output_redir_mode(cmd->tokens[arg_i - 1]), STDOUT_FILENO));
	else if (ft_strcmp(cmd->tokens[arg_i - 1], "<<") == 0)
	{
		if ()
			return (FALSE);
		return (file_redir());
	}
	else if (ft_strcmp(cmd->tokens[arg_i - 1], "<") == 0)
		return (file_redir(&cmd->in, cmd->tokens[arg_i], O_RDONLY, STDIN_FILENO));
	return (FALSE);
}

bool	file_redir(t_redir *shell_redir, char *file, int mode, int to_replace)
{
	int	fd;

	fd = open(file, mode, 0666);
	if (fd == -1)
		return (put_error("minishell", file, strerror(errno)));
	start_redir(shell_redir, to_replace, fd);
	return (TRUE);
}

void	start_redir(t_redir *shell_redir, int to_replace, int replacement)
{
	if (shell_redir->fd_backup != -1)
		stop_redir(shell_redir);
	shell_redir->fd_replaced = to_replace;
	shell_redir->fd_backup = dup(to_replace);
	dup2(replacement, to_replace);
	close(replacement);
}

void	stop_redir(t_redir *shell_redir)
{
	if (shell_redir->fd_backup == -1)
		return ;
	dup2(shell_redir->fd_backup, shell_redir->fd_replaced);
	close(shell_redir->fd_backup);
	shell_redir->fd_backup = -1;
	shell_redir->fd_replaced = -1;
}
