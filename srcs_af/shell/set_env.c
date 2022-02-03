/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:24:06 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/03 17:36:21 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// get index of the env variable we want
ssize_t	get_env_index(t_shell *shell, char *key)
{
	char	*new_key;
	size_t	new_key_len;
	ssize_t	line_index;

	new_key = ft_append_str(key, "=", FALSE, FALSE);
	new_key_len = ft_strlen(new_key);
	line_index = -1;
	while (shell->env[++line_index] != NULL)
		if(ft_strncmp(new_key, shell->env[line_index], new_key_len) == 0)
			break ;
	free(new_key);
	if ((size_t) line_index >= ft_strarray_length(shell))		// check if the new env is good len
		return (-1);
	return (line_index);
}

// get the env variable name your key == key value to look for (eg. PATH, PWD, etc);
char	*get_env_var(t_shell *shell, char *key)
{
	ssize_t	env_index;

	if (key == NULL)
		return (NULL);
	if (ft_strcmp(key, "?") == 0)
		return ;
	env_index = get_env_index(shell, key);
	if (env_index == -1)
		return (NULL);
	return (ft_strdup(&shell->env[env_index][ft_strlen(key) + 1]));
}

// get the env variable and set the shell_env var for the shell struct
void	set_env(t_shell	*shell, char *key, char *value, bool free_val)
{
	ssize_t	env_index;
	size_t	line_index;
	char	**new_env;

	env_index = get_env_index(shell, key);
	new_env = ft_calloc(ft_strarray_length(shell) + 2, sizeof(char *));
	if (new_env == NULL)
		return ;
	if (env_index != -1)
		unset_env(shell, key);
	line_index = 0;
	while (shell->env[line_index] != NULL)
	{
		new_env[line_index] = ft_strdup(shell->env[line_index]);
		line_index++;
	}
	if (value == NULL)
		new_env[line_index] = ft_strdup(key);
	else
		new_env[line_index] = ft_append_str(key, ft_append_str("=", value, FALSE, free_val), FALSE, TRUE);
	new_env[line_index + 1] = NULL;
	ft_destroy_strarray(&shell->env);
	shell->env = new_env;
}
