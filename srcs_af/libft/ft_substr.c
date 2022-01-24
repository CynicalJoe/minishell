/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:03:11 by afulmini          #+#    #+#             */
/*   Updated: 2022/01/22 11:18:05 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	min_len(size_t len1, size_t len2)
{
	if (len1 > len2)
		return (len2);
	else
		return (len1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	idx;

	idx = 0;
	if (s == NULL)
		return (NULL);
	while (idx < start)
	{
		if (*(s + idx) == '\0')
			return (ft_strdup(""));
		idx++;
	}
	idx = 0;
	substring = (char *)ft_calloc(min_len(len,
				ft_strlen(s) - start) + 1, sizeof(char));
	while (idx < len && (*(s + start + idx) != 0))
	{
		*(substring + idx) = *(s + start + idx);
		idx++;
	}
	return (substring);
}
