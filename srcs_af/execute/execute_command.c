/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:54:38 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/15 21:47:23 by afulmini         ###   ########.fr       */
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

void	execute_command(t_shell *shell, t_cmd *cmd)
{
	char	*program;
	char	*program_path;

	if (cmd->args == NULL)
		return ;
	program = ft_str_tolower(cmd->args[0]);
	if (get_builtin(program) != NULL)
		get_builtin(program)(shell, cmd->args);
	else if (ft_contains_char(program, '/'))
	{
		if (check_if_exist(NULL, program))
			execute_program(shell, program, cmd);
		else
			put_error("minishell", "no such file or directory", cmd->args[0]);
	}
	else
	{
		program_path = get_program_path(shell, cmd->args[0]);
		execute_program(shell, program_path, cmd);
		free(program_path);
	}
}
