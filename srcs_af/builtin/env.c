/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:30:44 by afulmini          #+#    #+#             */
/*   Updated: 2022/03/04 18:49:24 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

ssize_t	ft_find_char(char *s, char c)
{
	ssize_t	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_contains_char(char *str, char c)
{
	if (ft_find_char(str, c) == -1)
		return (0);
	return (1);
}

void	my_env(t_shell *shell, char **cmd)
{
	size_t	i;

	if (cmd[1] != NULL)
	{
		put_error("env", "no arguments please", strerror(errno));
		shell->exit_status = 1;
		return ;
	}
	i = 0;
	while (shell->env[i] != NULL)
	{
		if (ft_contains_char(shell->env[i], '='))
			ft_putendl_fd(shell->env[i], 1);
		i++;
	}
	shell->exit_status = 0;
}
