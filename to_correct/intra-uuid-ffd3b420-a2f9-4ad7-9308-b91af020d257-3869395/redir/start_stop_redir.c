/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_stop_redir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:15:15 by afulmini          #+#    #+#             */
/*   Updated: 2022/03/02 10:28:38 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
