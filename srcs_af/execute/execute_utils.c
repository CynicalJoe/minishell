/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 19:16:32 by afulmini          #+#    #+#             */
/*   Updated: 2022/03/03 22:44:14 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_str_tolower(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		s[i] = (char)ft_tolower(s[i]);
		i++;
	}
	return (s);
}

bool	check_exec(t_shell *shell, t_cmd *cmd, char *path)
{
	if (path == NULL)
	{
		put_error("minishell", "command not found.", cmd->args[0]);
		shell->exit_status = 127;
		return (FALSE);
	}
	if (ft_strncmp(cmd->args[0], "./", 2) == 0
		|| ft_strncmp(cmd->args[0], "../", 3) == 0)
	{
		if (ft_strcmp(cmd->args[0], "./minishell") != 0)
		{
			put_error("minishell", "no such file or directory.", cmd->args[0]);
			shell->exit_status = 126;
			return (FALSE);
		}
	}
	return (TRUE);
}

void	waiting(t_shell *shell, t_cmd *cmd)
{
	int	status;

	waitpid(cmd->pid, &status, 0);
	if (WIFEXITED(status))
		shell->exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		shell->exit_status = 128 + WTERMSIG(status);
}
