/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenise_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:00:38 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/07 14:58:26 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
// token for redir
void	tokenise_redir(t_cmd_container *cmd_container, char redir)
{
	// frist append the last token to tokens
	next_token(cmd_container);
	// make a token for redir
	cmd_container->token = ft_append_char_to_str(cmd_container->token, redir);
	if (cmd_container->line[cmd_container->read_index + 1] == redir)		// check for double redir for appending instead of just writing
	{
		cmd_container->read_index++;
		cmd_container->token = ft_append_char_to_str(cmd_container->token, redir);
	}
	// add the single or double redir token to tokens
	next_token(cmd_container);
}
