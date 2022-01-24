/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 09:53:31 by afulmini          #+#    #+#             */
/*   Updated: 2022/01/24 10:08:53 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Ctrl + D => EOF
// catch Ctrl+C => SIGINT
void	ctrl_c_signal(int signal)
{
	(void)signal;
	if (!g_shell->in_execution)
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
	if (g_shell->is_in_execution)
		ft_putstr_nl("Quit: 3");
}
