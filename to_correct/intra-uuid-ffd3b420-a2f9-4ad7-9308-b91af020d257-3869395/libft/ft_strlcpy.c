/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 09:13:03 by afulmini          #+#    #+#             */
/*   Updated: 2022/01/22 11:18:02 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;

	if (dst == NULL)
		return (0);
	idx = 0;
	while (idx < dstsize && (*(src + idx) != 0))
	{
		*(dst + idx) = *(src + idx);
		idx++;
	}
	if (idx < dstsize)
		*(dst + idx) = *(src + idx);
	else if (idx != 0)
		*(dst + idx - 1) = '\0';
	return (ft_strlen(src));
}
