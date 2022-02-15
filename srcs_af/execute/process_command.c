/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:49:17 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/15 21:53:12 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	set_in_exec(t_shell *shell, bool state)
{
	shell->in_exec = state;
	if (state)
		signal(SIGQUIT, ctrl_backslash_signal);
	else
		signal(SIGQUIT, SIG_IGN);
}

void	process_commands(t_shell *shell, t_cmd_container *cmd_container)
{
	t_cmd	*current;

	if (get_cmd_size(cmd_container) <= 0)
		return ;
	set_in_exec(shell, TRUE);
	current = cmd_container->cmds[0];
	while (current != NULL)
	{
		if (current->piped)
			current = process_piped(shell, current);
		else
		{
			if (current->previous != NULL && current->previous->piped)
				start_shell_redirection(&current->in, STDOUT_FILENO,
					current->previous->pipe[0]);
			parse_cmd(shell, current);
			execute_command(shell, current);
			stop_shell_redirection(&current->out);
			stop_shell_redirection(&current->in);
			current = current->next;
		}
	}
	set_in_exec(shell, FALSE);
	destroy_cmd_container(cmd_container);
}
