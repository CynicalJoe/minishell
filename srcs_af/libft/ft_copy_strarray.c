/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_strarray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:34:42 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/16 12:14:46 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_copy_strarray(char **str_array)
{
	char	**new_array;
	size_t	index;

	new_array = NULL;
	index = 0;
	while (str_array[index])
	{
		new_array = ft_addstr_to_strarray(new_array,
				ft_strdup(str_array[index]),
				TRUE);
		index++;
	}
	return (new_array);
}
