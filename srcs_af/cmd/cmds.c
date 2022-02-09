/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:17:32 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/09 10:55:47 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// create command_struct to use for our exec and redir
// create each command with its cmd as cmd->*tokens[0] and args as cmd->*tokens[n>0] ( only | and ; are command seperators )
t_cmd	*create_cmd(size_t i, char **args)	// **args are all the tokens from cmd_container
{
	t_cmd	*cmd;

	cmd = ft_calloc(1, sizeof(t_cmd));
	if (cmd == NULL)
		return (NULL);
	cmd->index = i;
	cmd->tokens = args;
	cmd->args = NULL;
	cmd->size = ft_strarray_length(args);
	cmd->previous = NULL;
	cmd->next = NULL;
	cmd->pid = -1;
	return (cmd);
}

// free t_cmd and elems
void	*destroy_cmd(t_cmd *cmd)
{
	if (cmd != NULL)
	{
		ft_destroy_strarray(&cmd->tokens);
		ft_destroy_strarray(&cmd->args);
	}
	free(cmd);
	return (NULL);
}
