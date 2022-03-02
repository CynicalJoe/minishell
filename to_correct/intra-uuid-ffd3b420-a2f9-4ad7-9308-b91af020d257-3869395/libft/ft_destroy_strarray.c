/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_strarray.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 09:15:45 by afulmini          #+#    #+#             */
/*   Updated: 2022/01/24 09:17:58 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_destroy_strarray(char ***str_array)
{
	size_t	idx;

	if (*str_array != NULL)
	{
		idx = 0;
		while ((*str_array)[idx])
		{
			free((*str_array)[idx]);
			(*str_array)[idx] = NULL;
			idx++;
		}
		free(*str_array);
		*str_array = NULL;
	}
	return (NULL);
}
