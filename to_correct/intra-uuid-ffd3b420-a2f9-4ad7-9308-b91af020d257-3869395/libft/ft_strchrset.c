/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 11:02:58 by afulmini          #+#    #+#             */
/*   Updated: 2022/01/22 11:17:58 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchrset(const char *s, char *charset)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (!is_charset(*str, charset) && (*str != 0))
		str++;
	if (!is_charset(*str, charset))
		return (NULL);
	return ((char *)str);
}
