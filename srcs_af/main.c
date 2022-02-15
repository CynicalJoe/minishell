/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:07:47 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/15 14:08:53 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	cmd_container->line = line;
}

int	main(int ac, char **av, char **env)
{
	t_shell			shell;
	t_cmd_container	*cmd_container;
	//t_cmd			*current;

	(void)av;
	shell = create_shell(env);
	g_shell = &shell;
	// update shell level using export ->
	if (ac != 1)
		exit_shell(&shell, "minishell does not take any arguments.", 1);
	cmd_container = &shell.cmd_container;
	signal(SIGINT, ctrl_c_signal);
	signal(SIGQUIT, SIG_IGN);	// if Ctrl + backslash ==> ignore signal
	while (TRUE)
	{
		set_line(cmd_container, readline(shell.prompt));		// prompt for the user
		if (cmd_container->line == NULL)
			exit_shell(&shell, "Bye :)", 0);
		if (ft_strlen(cmd_container->line) > 0)
		{
			add_history(cmd_container->line);
			//printf("%s\n", cmd_container->line);
			//printf("%zu\n", ft_strlen(cmd_container->line));
			//printf("number of tokens = %d\n", (int)cmd_container->cmds->size);
			if (!tokenise(cmd_container))
			{
				continue;
			}
		//	printf("this is the container == \n");
		//	display_cmd_container(cmd_container);		// parse and tokenise outpu if == 1 not good
		//	printf("this is the container == \n");
		//	display_cmd_container(cmd_container);
		//	printf("%s \n", cmd_container->line);
			// execute commands parsed and redir them ...
		//	printf("this is the container == \n");
		//	display_cmd_container(cmd_container);
			process_commands(&shell, cmd_container);
		//	destroy_cmd_container(cmd_container);
		}
	}
	return (0);
}


// Things to do ==> update SHLVL for each call of the program
// just parse line for the minishell command?
