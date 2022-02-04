/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:49:47 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/04 16:42:41 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	*get_export_key(char *var)
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
	ssize_t	equal_index;
	char	*key;

	equal_index = ft_find_char(var, '=');		// define function in libft
	key = get_export_key(var);
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

	sorted_env = ft_sort_str_array(shell->env);			//define function in libft
	i = 0;
	while (sorted_env[i] != NULL)
	{
		ft_putstr_fd("declare -x", 1);
		ft_putendl_fd(sorted_env[i], 1);
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
		if (is_alpha(cmd[i][0]) || cmd[i][0] == '-')
			export_var(shell, cmd[i]);
		else
		{
			put_error("minishell", cmd[i], "not a valid identifier.");
			shell->exit_status = 1;
			return ;
		}
		i++;
	}
}
