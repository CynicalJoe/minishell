/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:22:30 by afulmini          #+#    #+#             */
/*   Updated: 2022/03/03 20:54:48 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	my_pwd(t_shell *shell, char **args)
{
	char	*pwd;

	(void)shell;
	(void)args;
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
	{
		put_error("pwd", "getcwd error", strerror(errno));
		shell->exit_status = 1;
		return ;
	}
	ft_putendl_fd(pwd, 1);
	free(pwd);
	shell->exit_status = 0;
}
