/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:05:21 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/08 11:58:06 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// get size of each command from the cmd_container struct
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
