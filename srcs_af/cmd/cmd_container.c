/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_container.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:11:15 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/06 15:55:29 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// init cmd_container struct
void	init_container(t_cmd_container *cmd_container)
{
	cmd_container->line = NULL;
	cmd_container->read_index = 0;
	cmd_container->cmds = NULL;
	cmd_container->token = NULL;
	cmd_container->tokens = NULL;
}

// destroy cmd_cnotainer struct
void	*destroy_cmd_container(t_cmd_container *cmd_container)
{
	size_t	i;

	if (cmd_container != NULL)
	{
		free(cmd_container->line);
		cmd_container->line = NULL;
		cmd_container->read_index = 0;
		i = 0;
		while (i < get_cmds_size(cmd_container))
		{
			destroy_cmd(cmd_container->cmds[i]);
			i++;
		}
		free(cmd_container->cmds);
		cmd_container->cmds = NULL;
		cmd_container->tokens = ft_destroy_strarray(&cmd_container->tokens);
		free(cmd_container->token);
		cmd_container->token = NULL;
	}
	return (NULL);
}

// optional and best used for testing
void	display_cmd_container(t_cmd_container *cmd_container)
{
	t_cmd	*current;

	if (cmd_container->cmds == NULL)
		return ;
	current = cmd_container->cmds[0];
	while (current != NULL)
	{
		display_cmd(current);
		current = current->next;
	}
}
