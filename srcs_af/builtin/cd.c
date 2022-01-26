/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:15:21 by afulmini          #+#    #+#             */
/*   Updated: 2022/01/26 12:37:51 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	cd(t_shell *shell, char **cmd)
{
	char	*path;
	char	*old_pwd;

	if (cmd[1] == NULL || ft_strcmp(cmd[1], "~") == 0)
		path = get_env_var(shell, "HOME");
	else
		path = ft_strdup(cmd[1]);
	if (path == NULL)
		return ;
	old_pwd = getcwd(NULL, 0);
	if (chdir(path) == -1)
	{
		// print error ==> ("cd", path, strerror(errno));
		shell->exit_status = 1;
	}
	else
	{
		set_env_var(shell, "OLDPWD", old_pwd, FALSE);
		update_prompt(shell);
		shell->exit_status = 0;
	}
	free(path);
	free(old_pwd);
}
