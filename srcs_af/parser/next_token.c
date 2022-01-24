/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:20:24 by afulmini          #+#    #+#             */
/*   Updated: 2022/01/24 13:29:55 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	next_token(t_cmd_container *cmd_container)
{
	if (cmd_container->token == NULL)
		return ;
	cmd_container->tokens = ft_append_str_to_str_array(cmd_container->tokens,
			cmd_container->token, TRUE);
	cmd_container->token = NULL;
}
