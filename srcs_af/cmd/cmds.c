/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:17:32 by afulmini          #+#    #+#             */
/*   Updated: 2022/03/04 21:22:42 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_cmd	*create_cmd(size_t i, char **args)
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
	cmd->in = -1;
	cmd->out = -1;
	cmd->temp_file = NULL;
	cmd->piped = FALSE;
	return (cmd);
}

void	*destroy_cmd(t_cmd *cmd)
{
	if (cmd != NULL)
	{
		ft_destroy_strarray(&cmd->tokens);
		ft_destroy_strarray(&cmd->args);
		close_fd(cmd);
	}
	free(cmd);
	return (NULL);
}
