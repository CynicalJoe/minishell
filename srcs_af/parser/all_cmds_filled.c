/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_cmds_filled.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:59:30 by afulmini          #+#    #+#             */
/*   Updated: 2022/01/22 18:59:45 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// check is commands are filled
t_bool	all_cmds_filled(t_cmd_container *cmd_container)
{
	size_t	cmd_idx;

	cmd_idx = 0;
	while (cmd_idx < get_cmds_size(cmd_container))
	{
		if (cmd_container->cmds[cmd_idx]->tokens == NULL)
		{
			is_error(NULL, NULL, "found empty command.", EXIT_FAILURE);
			return (FALSE);
		}
		cmd_idx++;
	}
	return (TRUE);
}
