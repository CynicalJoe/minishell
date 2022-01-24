/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarray_length.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:06:09 by afulmini          #+#    #+#             */
/*   Updated: 2022/01/24 09:11:27 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strarray_length(char **str_array)
{
	size_t	len;

	len = 0;
	if (str_array == NULL)
		return (len);
	while (str_array[len] != NULL)
		len++;
	return (len);
}
