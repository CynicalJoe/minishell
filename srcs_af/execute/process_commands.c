/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 09:34:39 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/14 11:18:12 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell"

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

	if (get_cmds_size(cmd_container) <= 0)
		return ;
	set_in_exec(shell, TRUE);
	current = cmd_container->cmds[0];
	while (current != NULL)
	{
		if (current->piped)
			current = process_pipes(shell, current);
		else
		{
			if (current->previous !+ NULL && current->previous->piped)
				start_shell_redir();
			parse_cmd(shell, current);
			execute_cmd(shell, current);
			stop_shell_redir();
			stop_shell_redir();
			current = current->next;
		}
	}
	set_in_exec(shell, FALSE);
	destroy_cmd_container(cmd_container);
}
