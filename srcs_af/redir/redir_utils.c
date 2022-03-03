/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:47:24 by afulmini          #+#    #+#             */
/*   Updated: 2022/03/02 20:16:35 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	output_redir_mode(char *redirection)
{
	if (ft_strcmp(redirection, ">>") == 0)
		return (O_APPEND);
	else if (ft_strcmp(redirection, ">") == 0)
		return (O_TRUNC);
	return (0);
}

char	*temp_file_gen(void)
{
	int		i;
	char	*name;

	i = 0;
	while (i <= INT_MAX)
	{
		name = ft_itoa(i);
		if (!name)
			return (NULL);
		if (access(name, F_OK) != 0)
			break ;
		free(name);
		if (i == INT_MAX)
			return (NULL);
		i++;
	}
	return (name);
}
