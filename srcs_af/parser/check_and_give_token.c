/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_give_token.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:19:46 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/08 12:59:58 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// check the line and the types of token each char represents
void	check_and_give_token(t_cmd_container *cmd_container, char c)
{
	if (c == ' ')
		next_token(cmd_container);
	else if (c == '\'' || c == '\"')
		tokenise_quote(cmd_container, c);
	else if (c == '>' || c == '<')
		tokenise_redir(cmd_container, c);
	else if (c == '|')	// send pipe flag for the precedent cmd
		tokenise_pipe(cmd_container);
	// not necessary to process this ==> we can ignore this flag and put up an error
	else if (c == ';')		// not necessary to process this ==> we can ignore this flag and put up an error
		next_cmd(cmd_container);	// defined but not necessary for the minishell subject

	// if not special char add to cmd_container->token
	// last token gets the NULL value
	else
		cmd_container->token = ft_append_char_to_str(cmd_container->token, c);	// 
}
