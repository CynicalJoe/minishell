/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:43:57 by afulmini          #+#    #+#             */
/*   Updated: 2022/03/04 14:05:12 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

bool	check_redir(char **tokens, int i)
{
	if (is_redir(tokens[i]))
	{
		if (is_redir(tokens[i + 1]))
		{
			put_error("minishell", "syntax error near unexpected token",
				tokens[i]);
			return (FALSE);
		}
		else if (tokens[i + 1] == NULL)
		{
			put_error("minishell", "syntax error near unexpected token",
				"newline");
			return (FALSE);
		}
	}
	return (TRUE);
}

bool	check_cmd(t_cmd *cmds)
{
	size_t	i;

	if (cmds == NULL)
		return (FALSE);
	if (cmds->tokens != NULL)
	{
		i = 0;
		while (cmds->tokens[i] != NULL)
		{
			if (!check_redir(cmds->tokens, i))
				return (FALSE);
			i++;
		}
	}
	return (TRUE);
}

bool	check_cmd_container(t_cmd_container *cmd_container)
{
	t_cmd	*current;

	if (cmd_container->cmds == NULL)
		return (FALSE);
	current = *cmd_container->cmds;
	while (current != NULL)
	{
		if (!check_cmd(current))
			return (FALSE);
		current = current->next;
	}
	return (TRUE);
}
