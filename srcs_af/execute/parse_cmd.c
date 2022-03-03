/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:25:24 by afulmini          #+#    #+#             */
/*   Updated: 2022/03/03 16:02:44 by afulmini         ###   ########.fr       */
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
	unlink(cmd->in.temp_file);
	free(cmd->in.temp_file);
}

/* static void	check_redir(t_cmd *cmd, size_t index, size_t temp)
{

} */

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
			if (!dispatch_redir(shell, cmd, temp_index))
			{
				ft_destroy_strarray(&args);
				free(temp_index);
				return ;
			}
		}
		else
			args = ft_append_str_to_str_array(args,
					get_processed_arg(shell, cmd->tokens[index]), TRUE);
		if (index + 1 < *temp_index)
			index = *temp_index;
		else
			index++;
	}
	free(temp_index);
	cmd->args = args;
	if (cmd->in.temp_file)
		cleaning(cmd);
}
