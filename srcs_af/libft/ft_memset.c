/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:09:21 by afulmini          #+#    #+#             */
/*   Updated: 2022/01/22 11:17:39 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*res;
	size_t			idx;

	res = (unsigned char *)b;
	idx = 0;
	while (idx < len)
	{
		*res = (unsigned char)c;
		res++;
		idx++;
	}
	return (b);
}
