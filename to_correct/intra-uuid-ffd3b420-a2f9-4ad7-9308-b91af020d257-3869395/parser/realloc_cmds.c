/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:53:46 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/07 14:58:26 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// allocates memory for the t_cmd struct and returns pointer to it
t_cmd	**realloc_cmds(t_cmd_container *cmd_container)
{
	size_t	cmds_size;
	t_cmd	**new_cmds;
	size_t	i;

	cmds_size = get_cmd_size(cmd_container);
	new_cmds = ft_calloc(cmds_size + 2, sizeof(t_cmd));
	if (new_cmds == NULL)
		new_cmds = NULL;
	i = 0;
	while (i < cmds_size)
	{
		new_cmds[i] = cmd_container->cmds[i];
		i++;
	}
	new_cmds[i + 1] = NULL;
	return (new_cmds);
}
