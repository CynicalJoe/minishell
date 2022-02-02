/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:17:32 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/02 12:21:31 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// create command_struct to use for our exec and redir
t_cmd	*create_cmd(size_t i, char **args)	// **args are all the tokens to send to the command struct
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

void	destroy_cmd(t_cmd *cmd)
{
	if (cmd != NULL)
	{
		ft_destroy_strarray(&cmd->tokens);
		ft_destroy_strarray(&cmd->args);
	}
	free(cmd);
	return (NULL);
}

// get size of each command from the cmd_container struct
size_t	get_cmds_size(t_cmd_container *cmd_container)
{
	size_t	size;

	if (cmd_container->cmds == NULL)
		return (0);
	size = 0;
	while (cmd_container->cmds[size] != NULL)
		size++;
	return (size);
}

// optional ==> used for the tests and check all the inputs we will send to the cmd_struct
void	display_cmd(t_cmd *cmd)
{
	size_t	cmd_part_index;

	if (cmd == NULL)
		return ;
	ft_putstr_fd("Command ", 1);
	ft_putnbr(cmd->index);
	if (cmd->piped)
		ft_putstr_fd(" (piped)", 1);
	ft_putendl_fd(":",1);
	if (cmd->tokens != NULL)
	{
		cmd_part_index = 0;
		while (cmd->tokens[cmd_part_index] != NULL)
		{
			ft_putnbr(cmd_part_index);
			ft_putstr_fd(" - ", 1);
			ft_putendl_fd(cmd->tokens[cmd_part_index], 1);
			cmd_part_index++;
		}
	}
	else
		ft_putstrdl_fd("(null)");
}
