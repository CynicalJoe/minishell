/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 09:34:44 by afulmini          #+#    #+#             */
/*   Updated: 2022/01/24 10:08:51 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// destroy and free shell struct
void	*destroy_shell(t_shell *shell)
{
	if (shell != NULL)
	{
		shell->env = ft_destroy_strarray(&shell->env);
		free(shell->prompt);
		shell->prompt = NULL;
		destroy_cmds(&shell->cmd_container);
	}
	return (NULL);
}

// exit the shell destroying the struct we create for the env and shell -> 
void	exit_shell(t_shell *shell, char*message, int exit_code)
{
	if (message != NULL)
		ft_putendl_fd(message, 2);
	destroy_shell(shell);
	return (exit_code);
}
