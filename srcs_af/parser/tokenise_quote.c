/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenise_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:18:36 by afulmini          #+#    #+#             */
/*   Updated: 2022/01/22 19:18:58 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// token for quotes
void	tokenise_quote(t_cmd_container *cmd_container, char quote)
{
	char	current_char;

	cmd_container->token = ft_append_char_to_str(cmd_container->token, quote);
	cmd_container->read_index++;
	current_char = cmd_container->line[cmd_container->read_index];
	while (current_char && current_char != quote)
	{
		cmd_container->token = ft_append_char_to_str(cmd_container->token, current_char);
		cmd_container->read_index++;
		current_char = cmd_container->line[cmd_container->read_index];
	}
	cmd_container->token = ft_append_char_to_str(cmd_container->token, quote);
}