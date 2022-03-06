/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 09:05:13 by afulmini          #+#    #+#             */
/*   Updated: 2022/03/04 20:10:24 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	my_unset(t_shell *shell, char **cmd)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (cmd[i] != NULL)
	{
		j = 0;
		while (cmd[i][j] != '\0')
		{
			if (ft_isalpha(cmd[i][j]) || cmd[i][j] == '_')
				j++;
			else
			{
				put_error("unset", cmd[i], "not a valid identifier");
				shell->exit_status = 1;
				return ;
			}
		}
		unset_env_var(shell, cmd[i]);
		i++;
	}
	shell->exit_status = 0;
}
