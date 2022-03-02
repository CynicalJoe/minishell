/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addstr_to_strarray.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:06:54 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/03 17:34:31 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_addstr_to_strarray(char **array, char *str, bool free_array)
{
	char	**res;
	size_t	len;
	size_t	i;

	if (str == NULL)
		return (NULL);
	len = ft_strarray_length(array);
	res = ft_calloc(len + 2, sizeof(char *));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = array[i];
		i++;
	}
	res[i] = str;
	res[i + 1] = NULL;
	if (free_array)
		free(array);
	return (res);
}
