/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:25:24 by afulmini          #+#    #+#             */
/*   Updated: 2022/03/06 23:01:01 by afulmini         ###   ########.fr       */
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

static void	cleaning(t_cmd *cmd)
{
	unlink(cmd->temp_file);
	free(cmd->temp_file);
}

bool	parse_redir(t_shell *shell, t_cmd *cmd, size_t *temp, char **args)
{
	if (!dispatch_redir(shell, cmd, temp))
	{
		ft_destroy_strarray(&args);
		free(temp);
		return (FALSE) ;
	}
	return (TRUE);
}

size_t	check(size_t index, size_t *temp)
{
	if (index + 1 < *temp)
		return (index = *temp);
	else
		return (index + 1);
}

void	end_parse(size_t *temp, t_cmd *cmd, char **args)
{
	free(temp);
	cmd->args = args;
	if (cmd->temp_file)
		cleaning(cmd);
}

void	parse_cmd(t_shell *shell, t_cmd *cmd)
{
	char	**args;
	size_t	index;
	size_t	*temp_index;

	args = NULL;
	index = 0;
	temp_index = malloc(sizeof(size_t));
	*temp_index = 0;
	while (index < cmd->size)
	{
		if (is_redir(cmd->tokens[index]))
		{
			index++;
			*temp_index = index;
			if (!parse_redir(shell, cmd, temp_index, args))
				return;
		}
		else
			args = ft_append_str_to_str_array(args,
					get_processed_arg(shell, cmd->tokens[index]), TRUE);
		index = check(index, temp_index);
	}
	end_parse(temp_index, cmd, args);
}
