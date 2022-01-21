#include "../../inc/minishell.h"

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

void	ctrl_backslash_signal(int signal)
{
	(void)signal;
	if (g_shell->is_in_execution)
		ft_putstr_nl("Quit: 3");
}
