/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtournay <gtournay@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 14:59:51 by gtournay          #+#    #+#             */
/*   Updated: 2020/09/12 13:23:18 by gtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dest, void *src, size_t len)
{
	unsigned char		*d;
	unsigned char		*s;
	long unsigned int	i;

	if (!src && !dest)
		return (NULL);
	d = dest;
	s = src;
	i = 0;
	if (d < s)
	{
		while (i < len)
		{
			*(d + i) = *(s + i);
			i++;
		}
	}
	else
	{
		while (len--)
			*(d + len) = *(s + len);
	}
	return (dest);
}
