/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 21:26:06 by afulmini          #+#    #+#             */
/*   Updated: 2022/01/22 11:18:01 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_length;
	size_t	idx;
	size_t	src_length;

	dst_length = ft_strlen(dst);
	if (dstsize <= dst_length)
		return (dstsize + ft_strlen(src));
	src_length = dstsize - dst_length - 1;
	idx = 0;
	while (*(src + idx) && src_length--)
	{
		*(dst + dst_length + idx) = *(src + idx);
		idx++;
	}
	*(dst + dst_length + idx) = 0;
	return (dst_length + ft_strlen(src));
}
