/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:07:47 by afulmini          #+#    #+#             */
/*   Updated: 2022/03/04 10:44:32 by afulmini         ###   ########.fr       */
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

/*

void	display_cmd_container(t_cmd_container *cmd_container)
{
	t_cmd	*current;

	if (cmd_container->cmds == NULL)
		return ;
	current = cmd_container->cmds[0];
	while (current != NULL)
	{
		display_cmd(current);
		current = current->next;
	}
}

void	display_cmd(t_cmd *cmd)
{
	size_t	cmd_part_index;

	if (cmd == NULL)
		return ;
	ft_putstr_fd("Command ", 1);
	ft_putnbr_fd(cmd->index, 1);
	if (cmd->piped)
		ft_putstr_fd(" (piped)", 1);
	ft_putendl_fd(":", 1);
	if (cmd->tokens != NULL)
	{
		cmd_part_index = 0;
		while (cmd->tokens[cmd_part_index] != NULL)
		{
			ft_putnbr_fd(cmd_part_index, 1);
			ft_putstr_fd(" - ", 1);
			ft_putendl_fd(cmd->tokens[cmd_part_index], 1);
			cmd_part_index++;
		}
	}
	else
		ft_putendl_fd("(null)", 1);
}
*/