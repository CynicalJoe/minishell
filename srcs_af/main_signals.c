
#include "include/minishell.h"

void	ctrl_backslash_signal(int sig)
{
	(void)sig;
	if (g_shell->in_exec)
		ft_putendl_fd("Quit: 3", 1);	// check the quit error message
}

void	ctrl_c_signal(int sig)
{
	(void)sig;
	if (g_shell->in_exec)
	{
		ft_putchar_fd('\n',1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	else
		ft_putchar_fd('\n', 1);
}

/* 
void	main_sig_handler(int signal)
{
	if (signal == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		g_exit_code = 1;
	}
	else if (signal == SIGQUIT)
		rl_on_new_line();
	rl_redisplay();
}

void	sigint_n_sigquit_handler(void (*sigfunction))
{
	signal(SIGINT, sigfunction);
	signal(SIGQUIT, sigfunction);
}

void	unexp_eof_sigint_handler(int signal)
{
	if (signal == SIGINT)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_exit_code = 1;
	}
}
 */