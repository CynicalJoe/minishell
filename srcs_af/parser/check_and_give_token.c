/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_give_token.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:19:46 by afulmini          #+#    #+#             */
/*   Updated: 2022/01/23 15:54:15 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// check the line and the types of token each char represents
void	check_and_give_token(t_cmd_container *cmd_container, char c)
{
	if (c == ' ')
		next_token(cmd_container);
	else if (c == '\'' || c == '\"')
		tokenise_quote(cmd_container, c);
	else if (c == '>' || c == '<')
		tokenise_redir(cmd_container, c);
	else if (c == '|')
		tokenise_pipe(cmd_container);
	else if (c == ';')
		next_cmd(cmd_container);		// define !!!!!!!!!
	else
		cmd_container->token = ft_append_char_to_str(cmd_container->token, c);	// 
}
