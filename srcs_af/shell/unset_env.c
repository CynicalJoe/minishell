/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:14:06 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/05 18:14:35 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// unset the shell->env var and update
void	unset_env_var(t_shell *shell, char *key)
{
	ssize_t	env_index;
	char	**new_env;
	size_t	line_index;
	size_t	new_index;

	env_index = get_env_index(shell, key);
	if (env_index == -1)
		return ;
	new_env = ft_calloc(get_env_len(shell), sizeof(char *));
	if (new_env == NULL)
		return ;
	new_index = 0;
	line_index = 0;
	while (shell->env[line_index] != NULL)
	{
		if (line_index != (size_t)env_index)
		{
			new_env[new_index] = ft_strdup(shell->env[line_index]);
			new_index++;
		}
		line_index++;
	}
	new_env[new_index] = NULL;
	ft_destroy_strarray(&shell->env);
	shell->env = new_env;
}
