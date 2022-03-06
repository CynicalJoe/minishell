/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:07:47 by afulmini          #+#    #+#             */
/*   Updated: 2022/03/06 18:10:38 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

void	set_line(t_cmd_container *cmd_container, char *line)
{
	free(cmd_container->line);
	cmd_container->line = line;
}

void	loop(t_shell shell, t_cmd_container *cmd_container, bool check)
{
	bool	verif;

	verif = check;
	while (verif)
	{
		verif = TRUE;
		set_line(cmd_container, readline(shell.prompt));
		if (cmd_container->line == NULL)
			exit_shell(&shell, "\033[1;31mGoodbye :) \033[0m", 0);
		if (ft_strlen(cmd_container->line) > 0)
		{
			add_history(cmd_container->line);
			if (!tokenise(cmd_container))
				continue ;
			if (!check_cmd_container(cmd_container))
			{
				shell.exit_status = 258;
				check = FALSE;
				destroy_cmd_container(cmd_container);
			}
			else
				process_commands(&shell, cmd_container);
		}
	}
}

int	main(int ac, char **av, char **env)
{
	t_shell			shell;
	t_cmd_container	*cmd_container;
	bool			check;

	(void)av;
	shell = create_shell(env);
	g_shell = &shell;
	check = TRUE;
	if (ac != 1)
		exit_shell(&shell, "minishell does not take any arguments.", 1);
	cmd_container = &shell.cmd_container;
	signal(SIGINT, ctrl_c_signal);
	signal(SIGQUIT, SIG_IGN);
	loop(shell, cmd_container, check);
	return (0);
}
