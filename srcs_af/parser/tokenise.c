/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenise.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:56:03 by afulmini          #+#    #+#             */
/*   Updated: 2022/01/22 18:56:26 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// tokenise the input from the user and seperate it in the different structs
t_bool	tokenise(t_cmd_container *cmd_container)
{
	size_t	length;

	// check for quotes and if they are closed 
	if (!quotes_closed(cmd_container->line))	
		is_error(NULL, NULL, "unclosed quotes.", EXIT_FAILURE);
	length = ft_strlen(cmd_container->line);
	while(cmd_container->read_index < length)
	{
		check_and_give_token(cmd_container, cmd_container->line[cmd_container->read_index]);
		cmd_container->read_index++;
	}
	next_token(cmd_container);
	if (cmd_container->tokens != NULL)
		next_cmd(cmd_container);	// define this function to get the next command
	if (!all_cmds_filled(cmd_container) || get_cmds_size(cmd_container) == 0)	// check if the commands are all sent to the next struct, if not, quit
	{
		destroy_cmd_container(cmd_container);
		return (FALSE);
	}
	return (TRUE)
}