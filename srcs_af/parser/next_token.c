/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:20:24 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/03 16:26:21 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_append_str_to_str_array(char **strarray, char *str, bool free_array)
{
	char	*res;
	size_t	len;
	size_t	i;

	if (str == NULL)
		return (strarray);
	len = ft_strarray_length(strarray);
	res = ft_calloc(len + 2, sizeof(char *));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = strarray[i];
		i++;
	}
	res[i] = str;
	res[i + 1] = NULL;
	if (free_array)
		free(strarray);
	return (res);
}

// got to the next token -> meaning next arg in the cmd 
// if token NULL return 
// adds the token to tokens if not NULL 
void	next_token(t_cmd_container *cmd_container)
{
	if (cmd_container->token == NULL)
		return ;
	cmd_container->tokens = ft_append_str_to_str_array(cmd_container->tokens,
			cmd_container->token, TRUE);
	// set token to null after passed to tokens
	cmd_container->token = NULL;
}
