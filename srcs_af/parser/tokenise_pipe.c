/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenise_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:19:00 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/16 12:16:26 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// token for pipe
void	tokenise_pipe(t_cmd_container *cmd_container)
{
	next_cmd(cmd_container);
	cmd_container->cmds[get_cmd_size(cmd_container) - 1]->piped = 1;
}
