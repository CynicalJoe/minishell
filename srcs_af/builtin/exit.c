/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 08:56:30 by afulmini          #+#    #+#             */
/*   Updated: 2022/03/04 10:25:32 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

bool	only_numbers(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
		i++;
	if (i == ft_strlen(str))
		return (FALSE);
	while (str[i])
	{
		if (!ft_isdigit((int)str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	exit_action(t_shell *shell, int exit_code)
{
	ft_putendl_fd("\033[1;32mGoodbye :) \033[0m", 1);
	errno = exit_code;
	exit_shell(shell, NULL, exit_code);
}

void	my_exit(t_shell *shell, char **args)
{
	size_t	size;
	size_t	exit_code;

	size = ft_strarray_length(args);
	ft_putendl_fd("exit", 2);
	if (size == 1)
		exit_action(shell, 0);
	else if (size >= 2)
	{
		exit_code = ft_atol(args[1]);
		if (errno == ERANGE || !only_numbers(args[1]))
		{
			put_error("minishell", "exit", "numeric argument required.");
			exit_action(shell, 255);
		}
		if (size > 2)
			put_error("minishell", "exit", "too many arguments.");
		else
			exit_action(shell, exit_code % 256);
	}
}
