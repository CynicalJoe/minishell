/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:25:24 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/09 12:47:46 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*get_quotes_process()
{
	
}

bool	is_redir(char *arg)
{
	if (ft_strcmp(arg, ">>") == 0
		|| ft_strcmp(arg, ">") == 0
		|| ft_strcmp(arg, "<<") == 0
		|| ft_strcmp(arg, "<") == 0)
		return (TRUE);
	return (FALSE);
}

char	*processed_args(t_shell *shell, char *arg)
{
	char	*processed;
	size_t	len;
	size_t	i;

	processed = NULL;
	i = 0;
	len = ft_strlen(arg);
	while (i < len)
	{
		if (arg[i] == '\'' || arg[i] == '\"')
			processed = ft_append_str(processed, get_quotes_process(), TRUE, TRUE);
		else if (arg[i] == '$' && (ft_isalnum(arg[i + 1]) || arg[i + 1] == '?'))
			processed = ft_append_env_to_str(shell, processed, get_env_var_name(arg, len, &i));
		else
		{
			processed = ft_append_char_to_str(processed, arg[i]);
			i++;
		}
	}
	return (processed);
}

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
			if (!dispatch_redirection())  // dispatch the redirection  yet to define dipastch_redirection 
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
