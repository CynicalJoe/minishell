/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_strarray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:30:34 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/07 15:45:27 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_sort_strarray(char **strarray)
{
	char	**new;
	size_t	i;
	char	*tmp;

	new = ft_copy_strarray(strarray);
	i = 0;
	while (i < ft_strarray_length(new) - 1)
	{
		if (ft_strcmp(new[i], new[i + 1]) > 0)
		{
			tmp = new[i];
			new[i] = new[i + 1];
			new[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	return (new);
}
