/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:26:28 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/05 12:45:14 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

bool	is_numberstr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
		i++;
	if (i == ft_strlen(str))
		return (FALSE);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	exit_builtin_msg(t_shell *shell, int exit_code)
{
	ft_putstr("\033[0;32m");	// Green
	ft_putstr("Goodbye :)");
	ft_putendl("\033[0m", STDERR_FILENO);
	errno = exit_code;
	exit_shell(shell, NULL, exit_code);	// exit shell and output exit code
}

void	my_exit(t_shell *shell, char **args)
{
	size_t	size;
	size_t	exit_code;

	size = ft_strarray_length(args);
	ft_putendl_fd("exit", 2);
	if (size == 1)
		exit_builtin_msg(shell, 0);
	else if (size >= 2)
	{
		exit_code = ft_atol(args[1]);	// defined in libft
		if (errno == ERANGE || !is_numberstr(args[1])) 
		{
			put_error("minishell", "exit", "numeric argument required.");
			exit_builtin_msg(shell, 255);
		}
		if (size > 2)
			put_error("minishell", "exit", "too many arguments.");
		else
			exit_builtin_msg(shell, exit_code % 256);	//  the exit codes go from 0 to 255 and then repeat on a scale of 255	
	}
}
