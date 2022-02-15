/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 09:05:13 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/15 12:39:42 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	my_unset(t_shell *shell, char **cmd)
{
	size_t	i;

	i = 1;
	while (cmd[1] != NULL)
	{
		if (ft_isalpha(cmd[i][0]) || cmd[i][0] == '_')
			unset_env_var(shell, cmd[i]);
		else
		{
			put_error("unset", cmd[i], "not a valid identifier");
			shell->exit_status = 1;
			return ;
		}
		i++;
	}
	shell->exit_status = 0;
}
