/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:14:37 by afulmini          #+#    #+#             */
/*   Updated: 2022/01/22 11:17:35 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	tmp;
	unsigned char	*string;
	size_t			idx;

	idx = 0;
	string = (unsigned char *)s;
	tmp = (unsigned char)c;
	while (idx < n && *string != tmp)
	{
		string++;
		idx++;
	}
	if (idx == n)
		return (NULL);
	return (string);
}
