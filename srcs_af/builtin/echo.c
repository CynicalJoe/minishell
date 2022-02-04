/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 08:45:31 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/04 08:56:46 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	my_echo(t_shell *shell, char **cmd)
{
	int		print_nl;
	size_t	index;

	(void)shell;
	print_nl = 1;
	index = 0;
	while (cmd[index] != NULL && ft_strcmp(cmd[index], "-n") == 0)
	{
		print_nl = 0;
		index++;
	}
	while (cmd[index] != NULL)
	{
		ft_putstr_fd(cmd[index], 1);
		if (cmd[index + 1] == NULL)
			ft_putchar(' ');
		index++;
	}
	if (print_nl)
		ft_putchar('\n');
	shell->exit_status = 0;
}
