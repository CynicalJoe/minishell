/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_closed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:59:56 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/15 21:52:11 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	quotes_closed(char *str)
{
	int		is_open;
	size_t	strlen;
	size_t	index;
	char	current_quote;

	strlen = ft_strlen(str);
	is_open = 0;
	index = 0;
	while (index < strlen)
	{
		if (str[index] == '\'' || str[index] == '\"')
		{
			is_open = 1;
			current_quote = str[index];
			index++;
			while (index < strlen && str[index] != current_quote)
				index++;
			if (str[index] == current_quote)
				is_open = 0;
		}
		index++;
	}
	return (!is_open);
}
