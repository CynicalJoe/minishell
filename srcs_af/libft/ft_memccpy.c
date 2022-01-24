/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:23:10 by afulmini          #+#    #+#             */
/*   Updated: 2022/01/22 11:17:34 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			idx;
	unsigned char	*tmp;
	unsigned char	*dest;

	dest = (unsigned char *)dst;
	tmp = (unsigned char *)src;
	idx = 0;
	while (idx < n && (unsigned char)c != *tmp)
	{
		*dest++ = *tmp++;
		idx++;
	}
	if (idx != n)
		*dest = *tmp;
	else
		return (NULL);
	return (dest + 1);
}
