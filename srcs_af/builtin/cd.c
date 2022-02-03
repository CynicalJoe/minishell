/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:15:21 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/03 17:57:27 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	cd(t_shell *shell, char **cmd)
{
	char	*path;
	char	*old_pwd;
	char	*new_pwd;

	if (cmd[1] == NULL || ft_strcmp(cmd[1], "~") == 0)
		path = get_env_var(shell, "HOME");
	else
		path = ft_strdup(cmd[1]);
	if (path == NULL)
		return ;
	new_pwd = NULL;
	old_pwd = getcwd(NULL, 0);
	if (chdir(path) == -1)
	{
		// print error ==> ("cd", path, strerror(errno));
		shell->exit_status = 1;
	}
	else
	{
		new_pwd = getcwd(NULL, 0);
		set_env(shell, "OLDPWD", old_pwd, FALSE);
		set_env(shell, "PWD", new_pwd, FALSE);
		update_prompt(shell);
		shell->exit_status = 0;
	}
	free(path);
	free(old_pwd);
	free(new_pwd);
}
