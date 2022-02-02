/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:25:24 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/02 12:34:33 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	parse_cmd(t_shell *shell, t_cmd *cmd)
{
	char	**args;
	size_t	index;

	args = NULL;
	index = 0;
	while (index < cmd->size)
	{
		if (is_redir(cmd->tokens[index])) // check for redirection ==> define is_redirection
		{
			index++;
			if (!)  // dispatch the redirection  check and define dipastch_redirection 
			{
				ft_destroy_strarray(&args);
				return ;
			}
		}
		else
			args = ft_append_str_to_str_array(args, proccessed_args(shell, cmd->tokens[index]), TRUE);
		index++;
	}
	cmd->args = args;
}
