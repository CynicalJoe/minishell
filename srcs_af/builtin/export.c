/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:49:47 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/07 15:43:03 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	*get_export_var_key(char *var)
{
	char	*key;
	size_t	i;
	key = NULL;
	i = 0;
	while (var[i] && var[i] != '=')
	{
		key = ft_append_char_to_str(key, var[i]);
		i++;
	}
	return (key);
}

static void	export_var(t_shell *shell, char *var)
{
	ssize_t	equal_index;	// check the index of the char '='
	char	*key;

	equal_index = ft_find_char(var, '=');
	key = get_export_var_key(var);
	if (equal_index == -1)
		set_env(shell, var, NULL, FALSE);
	else
		set_env(shell, key, &var[equal_index + 1], FALSE);
	free(key);
	shell->exit_status = 0;
}

static void	display_env_var(t_shell *shell)
{
	char	**sorted_env;
	size_t	i;

	sorted_env = ft_sort_strarray(shell->env);
	i = 0;
	while (sorted_env[i] != NULL)
	{
		printf("declared: %s\n", sorted_env[i]);
		i++;
	}
	ft_destroy_strarray(&sorted_env);
	shell->exit_status = 0;
}

void	my_export(t_shell *shell, char **cmd)
{
	size_t	i;

	i = 1;
	if (cmd[i] == NULL)
		display_env_var(shell);
	while (cmd[i] != NULL)
	{
		if (ft_isalpha(cmd[i][0] || cmd[i][0] == '_'))
			export_var(shell, cmd[i]);
		else
		{
			put_error("export", cmd[i], "not valid identifier.");
			shell->exit_status = 1;
			return ;
		}
		i++;
	}
}
