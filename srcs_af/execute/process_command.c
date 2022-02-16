/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 08:10:59 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/16 10:22:14 by afulmini         ###   ########.fr       */
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
	while (current != NULL)
	{
		if (current->piped)
			current = process_piped(shell, current);	// piping process; // pipe the output of the current command to send it to the next		
		else
		{
			if (current->previous != NULL && current->previous->piped)
				start_redir();	// redir output/inputs
			parse_cmd(shell, current);
			execute_command(shell, current);
			current = current->next;
		}
	}
	set_in_exec(shell, FALSE);
	destroy_cmd_container(cmd_container);
}
