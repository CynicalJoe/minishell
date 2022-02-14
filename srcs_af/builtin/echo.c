/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 08:45:31 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/11 20:20:31 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// check for when we have -nnnnn
void	my_echo(t_shell *shell, char **cmd)
{
	bool	print_nl;
	size_t	index;

	(void)shell;
	print_nl = TRUE;
	index = 0;
	while (cmd[index] != NULL && ft_strcmp(cmd[index], "-n") == 0)
	{
		print_nl = FALSE;
		index++;
	}
	while (cmd[index] != NULL)
	{
		ft_putstr_fd(cmd[index], 1);
		if (cmd[index + 1] == NULL)
			ft_putchar_fd(' ', 1);
		index++;
	}
	if (print_nl)
		ft_putchar_fd('\n', 1);
	shell->exit_status = 0;
}
