/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:21:48 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/14 13:28:10 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// build the path to the builtin function according to the env 
char	*build_path(char *path, char *program)
{
	return (ft_append_str(path, ft_append_str("/", program, FALSE, FALSE), FALSE, TRUE));
}

// check if current command exists in the path given by env:
bool	check_if_exist(char *path, char *program)
{
	char			*full_path;
	struct	stat	buf;
	bool			res;

	if (path == NULL)
		full_path = program;
	else
		full_path = build_path(path, program);
	res = stat(full_path, &buf) == 0;	//check the validity of the requested path	--> if successful reutrns 0 and assign to res
	if (path != NULL)
		free(full_path);
	return (res);
}

// get the path of the builtin program
char	*get_program_path(t_shell *shell, char *program)
{
	char	*path_env;		// environment var pathname
	char	**splitted_path;	// usable paths for bin file
	size_t	index;
	char	*res;

	path_env = get_env_var(shell, "PATH");
	if (path_env == NULL)
		return (NULL);
	splitted_path = ft_split(path_env, ':');	// split the env path to get each elem;
	free(path_env);
	if (splitted_path == NULL)
		return (NULL);
	index = 0;
	while (splitted_path[index] != NULL)
	{
		if (check_if_exist(splitted_path[index], program))	// check if the cmd is a bash cmd 
		{
			res = build_path(splitted_path[index], program);
			ft_destroy_strarray(&splitted_path);
			return (res);
		}
		index++;
	}
	ft_destroy_strarray(&splitted_path);	// free strarray
	return (NULL);
}
