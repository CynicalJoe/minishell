/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:22:01 by afulmini          #+#    #+#             */
/*   Updated: 2022/03/04 21:45:32 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

bool	is_builtin(char *builtin_str)
{
	if (ft_strcmp(builtin_str, "cd") == 0)
		return (TRUE);
	else if (ft_strcmp(builtin_str, "echo") == 0)
		return (TRUE);
	else if (ft_strcmp(builtin_str, "env") == 0)
		return (TRUE);
	else if (ft_strcmp(builtin_str, "exit") == 0)
		return (TRUE);
	else if (ft_strcmp(builtin_str, "export") == 0)
		return (TRUE);
	else if (ft_strcmp(builtin_str, "unset") == 0)
		return (TRUE);
	else if (ft_strcmp(builtin_str, "pwd") == 0)
		return (TRUE);
	else
		return (FALSE);
}

void	get_builtin(char *builtin_str, t_shell *shell, char **cmd)
{
	if (ft_strcmp(builtin_str, "cd") == 0)
		my_cd(shell, cmd);
	else if (ft_strcmp(builtin_str, "echo") == 0)
		my_echo(shell, cmd);
	else if (ft_strcmp(builtin_str, "env") == 0)
		my_env(shell, cmd);
	else if (ft_strcmp(builtin_str, "exit") == 0)
		my_exit(shell, cmd);
	else if (ft_strcmp(builtin_str, "export") == 0)
		my_export(shell, cmd);
	else if (ft_strcmp(builtin_str, "unset") == 0)
		my_unset(shell, cmd);
	else if (ft_strcmp(builtin_str, "pwd") == 0)
		my_pwd(shell, cmd);
}
