/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 09:21:12 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/08 13:15:05 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// extract and create a struct for references in future use
char	**create_env(char **default_env)
{
	char	**new_env;
	size_t	line_index;

	new_env = ft_calloc(ft_strarray_length(default_env) + 1, sizeof(char *));
	if (new_env == NULL)
		return (NULL);
	line_index = 0;
	while (default_env[line_index] != NULL)
	{
		new_env[line_index] = ft_strdup(default_env[line_index]);
		line_index++;
	}
	new_env[line_index] = NULL;
	return (new_env);
}
