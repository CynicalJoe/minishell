/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_stop_redir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:15:15 by afulmini          #+#    #+#             */
/*   Updated: 2022/03/04 12:10:25 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

bool	file_redir(t_cmd *shell_redir, char *file, int mode, int redir)
{
	int	fd;

	fd = open(file, mode, 0666);
	if (fd == -1)
		return (put_error("minishell", file, strerror(errno)));
	start_redir(shell_redir, fd, redir);
	return (TRUE);
}

void	start_redir(t_cmd *shell_redir, int replacement, int mode)
{
	if (mode == 0)
	{
		if (shell_redir->in != -1)
			close(shell_redir->in);
		shell_redir->in = replacement;
	}
	else
	{
		if (shell_redir->out != -1)
			close(shell_redir->out);
		shell_redir->out = replacement;
	}
}
