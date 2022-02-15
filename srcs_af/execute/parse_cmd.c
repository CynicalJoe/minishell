/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:25:24 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/15 21:48:07 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

bool	is_redir(char *arg)
{
	if (ft_strcmp(arg, ">>") == 0
		|| ft_strcmp(arg, ">") == 0
		|| ft_strcmp(arg, "<<") == 0
		|| ft_strcmp(arg, "<") == 0)
		return (TRUE);
	return (FALSE);
}

void	parse_cmd(t_shell *shell, t_cmd *cmd)
{
	char	**args;
	size_t	index;

	args = NULL;
	index = 0;
	while (index < cmd->size)
	{
		if (is_redir(cmd->tokens[index]))
		{
			index++;
			if (!dispatch_redirection(cmd, index))
			{
				ft_destroy_strarray(&args);
				return ;
			}
		}
		else
			args = ft_append_str_to_str_array(args,
					get_processed_arg(shell, cmd->tokens[index]), TRUE);
		index++;
	}	
	cmd->args = args;
}
