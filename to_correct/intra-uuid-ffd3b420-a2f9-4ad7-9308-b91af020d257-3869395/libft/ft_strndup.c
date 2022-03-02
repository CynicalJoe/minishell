/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:48:10 by afulmini          #+#    #+#             */
/*   Updated: 2022/01/22 11:21:24 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*ret;
	size_t	len;
	size_t	i;

	len = 0;
	while (s1[len])
		len++;
	if (len > n)
		len = n;
	ret = (char *)ft_calloc(len + 1, 1);
	i = 0;
	while (i < len)
	{
		ret[i] = s1[i];
		i++;
	}
	return (ret);
}
