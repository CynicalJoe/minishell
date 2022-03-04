/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:22:01 by afulmini          #+#    #+#             */
/*   Updated: 2022/03/04 10:02:29 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	(*get_builtin(char *builtin_str))(t_shell *shell, char **cmd)
{
	if (ft_strcmp(builtin_str, "cd") == 0)
		return (&my_cd);
	else if (ft_strcmp(builtin_str, "echo") == 0)
		return (&my_echo);
	else if (ft_strcmp(builtin_str, "env") == 0)
		return (&my_env);
	else if (ft_strcmp(builtin_str, "exit") == 0)
		return (&my_exit);
	else if (ft_strcmp(builtin_str, "export") == 0)
		return (&my_export);
	else if (ft_strcmp(builtin_str, "unset") == 0)
		return (&my_unset);
	else if (ft_strcmp(builtin_str, "pwd") == 0)
		return (&my_pwd);
	else
		return (NULL);
}
