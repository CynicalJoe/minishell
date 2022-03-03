/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_stop_redir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:15:15 by afulmini          #+#    #+#             */
/*   Updated: 2022/03/03 16:28:46 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

bool	file_redir(t_redir *shell_redir, char *file, int mode)
{
	int	fd;

	fd = open(file, mode, 0666);
	if (fd == -1)
		return (put_error("minishell", file, strerror(errno)));
	start_redir(shell_redir, fd);
	return (TRUE);
}

void	start_redir(t_redir *shell_redir, int replacement)
{
	printf("redir sfd = %d\n", shell_redir->fd ); 
	if (shell_redir->fd != -1)
		close(shell_redir->fd);
	shell_redir->fd = replacement;
	printf("redir after = %d\n", shell_redir->fd ); 
}

void	stop_redir(t_redir *shell_redir)
{
	if (shell_redir->fd == -1)
		return ;
	dup2(shell_redir->fd, shell_redir->fd_replaced);
	close(shell_redir->fd);
	shell_redir->fd = -1;
	shell_redir->fd_replaced = -1;
}
