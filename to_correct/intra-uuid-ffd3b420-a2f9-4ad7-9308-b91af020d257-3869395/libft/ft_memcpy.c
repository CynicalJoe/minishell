/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:23:10 by afulmini          #+#    #+#             */
/*   Updated: 2022/01/22 11:17:37 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			idx;
	unsigned char	*tmp;
	unsigned char	*dest;

	if (dst == src)
		return (dst);
	dest = (unsigned char *)dst;
	tmp = (unsigned char *)src;
	idx = 0;
	while (idx < n)
	{
		*dest++ = *tmp++;
		idx++;
	}
	return (dst);
}
