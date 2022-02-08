/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenise.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:56:03 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/08 17:11:10 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// tokenise the input from the user and seperate it in the different structs
bool	tokenise(t_cmd_container *cmd_container)
{
	size_t	length;

	// check for quotes and if they are closed 
	if (!quotes_closed(cmd_container->line))
	{
		put_error("minishell", "error", "unclosed quotes");
		return (FALSE);
	}
	length = ft_strlen(cmd_container->line);
	while(cmd_container->read_index < length)
	{
		check_and_give_token(cmd_container, cmd_container->line[cmd_container->read_index]);
		cmd_container->read_index++;
	}
	next_token(cmd_container);	// add the last token
	// before this we put all the elements read in a **tokens struct 
	if (cmd_container->tokens != NULL)
		next_cmd(cmd_container);	// define this function to get the next command
		// next_cmd sends the tokens from cmd_container to the s_cmd struct to be processed and executed
	if (!all_cmds_filled(cmd_container) || get_cmd_size(cmd_container) == 0)	// check if the commands are all sent to the next struct, if not, quit
	{
		// free the container for the next command
		destroy_cmd_container(cmd_container);
		return (0);
	}
	return (1);
}
