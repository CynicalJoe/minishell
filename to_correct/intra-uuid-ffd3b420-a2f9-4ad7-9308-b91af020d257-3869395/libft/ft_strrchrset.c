/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchrset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:16:02 by afulmini          #+#    #+#             */
/*   Updated: 2022/01/22 11:21:54 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchrset(const char *s, char *charset)
{
	char	*str;
	int		len;
	int		k;

	if (!s || !charset)
		return (NULL);
	len = ft_strlen(s);
	str = (char *)s;
	while (len > 0)
	{
		k = -1;
		while (charset[++k])
			if (*(str + len) == charset[k])
				return (str + len);
		len--;
	}
	k = -1;
	while (charset[++k])
		if (*str == charset[k])
			return (str);
	return (NULL);
}
