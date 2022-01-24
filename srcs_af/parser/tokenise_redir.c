/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenise_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:00:38 by afulmini          #+#    #+#             */
/*   Updated: 2022/01/22 19:18:33 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
// token for redir
void	tokenise_redir(t_cmd_container *cmd_container, char redir)
{
	next_token(cmd_container);
	cmd_container->token = ft_append_char_to_str(cmd_container->token, redir);
	if (cmd_container->line[cmd_container->read_index + 1] == redir)		// check for double redir for appending instead of just writing
	{
		cmd_container->read_index++;
		cmd_container->token = ft_append_char_to_str(cmd_container->token, redir);
	}
	next_token(cmd_container);
}