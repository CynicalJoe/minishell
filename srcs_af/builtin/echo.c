/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 08:45:31 by afulmini          #+#    #+#             */
/*   Updated: 2022/03/04 22:27:32 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

bool	check_flag(char *cmd, int index, bool print_nl)
{
	bool	new_line;
	int		count;

	count = index;
	new_line = print_nl;
	while (cmd[count] != '\0')
	{
		if (cmd[count] == 'n')
			new_line = FALSE;
		if (cmd[count] != 'n')
		{
			new_line = TRUE;
			break ;
		}
		count++;
	}
	return (new_line);
}

void	my_echo(t_shell *shell, char **cmd)
{
	bool	print_nl;
	size_t	index;
	int		count;

	(void)shell;
	print_nl = TRUE;
	index = 1;
	while (cmd[index] != NULL && ft_strncmp(cmd[index], "-n", 2) == 0)
	{
		count = 1;
		print_nl = check_flag(cmd[index], count, print_nl);
		index++;
	}
	if (print_nl == TRUE)
		index = 1;
	while (cmd[index] != NULL)
	{
		ft_putstr_fd(cmd[index], 1);
		if (cmd[index + 1] != NULL)
			ft_putchar_fd(' ', 1);
		index++;
	}
	if (print_nl)
		ft_putchar_fd('\n', 1);
	shell->exit_status = 0;
}
