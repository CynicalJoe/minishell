/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 09:53:31 by afulmini          #+#    #+#             */
/*   Updated: 2022/03/04 21:23:20 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../libft/libft.h"

size_t	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

// Ctrl + D => EOF
// catch Ctrl+C => SIGINT
void	ctrl_c_signal(int signal)
{
	(void)signal;
	if (!g_shell->in_exec)
	{
		ft_putchar('\n');
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	else
		ft_putchar('\n');
}

// catch Ctrl+backslash	=> SIGQUIT
void	ctrl_backslash_signal(int signal)
{
	(void)signal;
	if (g_shell->in_exec)
		ft_putendl_fd("Quit: 3", 1);
}
