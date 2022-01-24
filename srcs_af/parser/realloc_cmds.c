/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:53:46 by afulmini          #+#    #+#             */
/*   Updated: 2022/01/23 16:56:57 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_cmd	**realloc_cmds(t_cmd_container *cmd_container)
{
	size_t	cmds_size;
	t_cmd	*new_cmds;
	size_t	i;

	cmds_size = get_cmd_size(cmd_container);	// define it
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
