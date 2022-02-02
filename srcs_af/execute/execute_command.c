/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:54:38 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/02 11:58:57 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	is_uppercase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

char	ft_lowercase_char(char c)
{
	if (is_uppercase(c))
		return (c + 32);
	return (c);
}

char	*ft_to_lower(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_lower_case(str[i]);
		i++;
	}
	return (str);
}

// execute the command extracted from temporary struct s_cmd
void	execute_command(t_shell *shell, t_cmd *cmd)
{
	char	*program;
	char	*program_path;

	if (cmd->args == NULL)
		return ;
	program = ft_to_lower(cmd->args[0]);
	if (get_builtin(program) != NULL)	// ==> check if the program is a builtin function we built
		get_builtin(program)(shell, cmd->args);	// check this type of function prototype
	else if (ft_contains_char(program, '/'))
	{
		if (check_if_exist(NULL, program))
			execute_program();	//define function in execute_program.c ==>
			// we need the shell the path and the cmd itself
		else
			put_error("minishell", "no such file or directory", cmd->args[0]);
	}
	else
	{
		program_path = get_program_path(shell, cmd->args[0]);
		execute_program();
		free(program_path);
	}
}
