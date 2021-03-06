/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 08:57:44 by afulmini          #+#    #+#             */
/*   Updated: 2022/03/03 14:31:48 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

size_t	get_cmd_size(t_cmd_container *cmd_container)
{
	size_t	size;

	if (cmd_container->cmds == NULL)
		return (0);
	size = 0;
	while (cmd_container->cmds[size] != NULL)
		size++;
	return (size);
}

size_t	get_nbr_tokens(t_cmd *cmd)
{
	size_t	size;

	size = 0;
	if (cmd->tokens == NULL)
		return (0);
	if (cmd->tokens != NULL)
	{
		while (cmd->tokens[size] != NULL)
			size++;
	}
	return (size);
}
