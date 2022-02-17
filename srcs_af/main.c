/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:07:47 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/17 08:59:40 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

void	set_line(t_cmd_container *cmd_container, char *line)
{
	free(cmd_container->line);
	cmd_container->line = line;
}

int	main(int ac, char **av, char **env)
{
	t_shell			shell;
	t_cmd_container	*cmd_container;

	(void)av;
	shell = create_shell(env);
	g_shell = &shell;
	if (ac != 1)
		exit_shell(&shell, "minishell does not take any arguments.", 1);
	cmd_container = &shell.cmd_container;
	signal(SIGINT, ctrl_c_signal);
	signal(SIGQUIT, SIG_IGN);
	while (TRUE)
	{
		set_line(cmd_container, readline(shell.prompt));
		if (cmd_container->line == NULL)
			exit_shell(&shell, "\033[0;31m Bye :) \033[0m", 0);
		if (ft_strlen(cmd_container->line) > 0)
		{
			add_history(cmd_container->line);
			if (!tokenise(cmd_container))
				continue ;
			process_commands(&shell, cmd_container);
		}
	}
	return (0);
}
