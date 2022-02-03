# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <limits.h>
# include <stdbool.h>
# include <errno.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>ß

# include "../libft/libft.h"
# include "include/minishell.h"
// # include "../../inc_af/minishell.h"

//			FUNCTIONS

// get current dir()
/* char	*printDir()
{
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    return (cwd);
} */

// setline to prompt and get user input
void	set_line(t_cmd_container *cmd_container, char *line)
{
	free(cmd_container->line);
	//cmd_container->line = printDir();
	cmd_container->line += (int)line;
}

//			TOKENISE

int	main(int ac, char **av, char **env)
{
	t_shell			shell;
	t_cmd_container	*cmd_container;


	(void)av;
	shell = create_shell(env);
	// update shell level using export ->
	if (ac != 1)
		exit_shell(&shell, "minishell does not take any arguments.\n", 1);
	cmd_container = &shell.cmd_container;
	signal(SIGINT, ctrl_c_signal);
	signal(SIGQUIT, SIG_IGN);	// if Ctrl + backslahs ==> ignore signal
	while (1)
	{
		set_line(cmd_container, readline(shell.prompt));		// prompt for the user
		if (cmd_container->line == NULL)
			exit_shell(&shell, "Bye :)", 0);
		if (ft_strlen(cmd_container->line) > 0)
		{
			add_history(cmd_container->line);
			if (!tokenise(cmd_container->line))		// parse and tokenise outpu if == 1 not good
				continue;
			// execute commands parsed and redir them ...
			// process_commands()
		}
	}
	return (EXIT_SUCCESS);
}


// Things to do ==> update SHLVL for each call of the program 