/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenise_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:19:00 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/08 11:58:06 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// token for pipe
void	tokenise_pipe(t_cmd_container *cmd_container)
{
	// set up the command before the pipe
	next_cmd(cmd_container);
	// update piped status of the command preceding this char
	// next command will receive the output of the precedent
	cmd_container->cmds[get_cmd_size(cmd_container) - 1]->piped = 1;
}
