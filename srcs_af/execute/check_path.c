/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:21:48 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/24 12:05:50 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*build_path(char *path, char *program)
{
	return (ft_append_str(path, ft_append_str("/",
				program, FALSE, FALSE), FALSE, TRUE));
}

bool	check_if_exist(char *path, char *program)
{
	char			*full_path;
	struct stat		buf;
	bool			res;

	res = FALSE;
	if (path == NULL)
		full_path = program;
	else
		full_path = build_path(path, program);
	res = stat(full_path, &buf) == 0;	// check if norminette of scholl accepts
	if (path != NULL)
		free(full_path);
	return (res);
}

char	*get_program_path(t_shell *shell, char *program)
{
	char	*path_env;
	char	**splitted_path;
	size_t	index;
	char	*res;

	path_env = get_env_var(shell, "PATH");
	if (path_env == NULL)
		return (NULL);
	splitted_path = ft_split(path_env, ':');
	free(path_env);
	if (splitted_path == NULL)
		return (NULL);
	index = 0;
	while (splitted_path[index] != NULL)
	{
		if (check_if_exist(splitted_path[index], program))
		{
			res = build_path(splitted_path[index], program);
			ft_destroy_strarray(&splitted_path);
			return (res);
		}
		index++;
	}
	ft_destroy_strarray(&splitted_path);
	return (NULL);
}
