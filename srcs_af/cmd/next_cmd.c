/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:35:11 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/09 10:53:43 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// container links to t_cmd
// creates a command in the t_cmd struct to work with
// sends the command to 
void	next_cmd(t_cmd_container *cmd_container)
{
	size_t	size;
	t_cmd	**new_cmds;

	size = get_cmd_size(cmd_container);
	new_cmds = realloc_cmds(cmd_container);
	new_cmds[size] = create_cmd(size, cmd_container->tokens);
	if (size > 0)
		new_cmds[size]->previous = new_cmds[size - 1];
	if (size > 0)
		new_cmds[size - 1]->next = new_cmds[size];
	new_cmds[size + 1] = NULL;
	cmd_container->tokens = NULL;
	free(cmd_container->cmds);
	cmd_container->cmds = new_cmds;
}
