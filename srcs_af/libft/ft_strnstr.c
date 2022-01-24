/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 12:49:21 by afulmini          #+#    #+#             */
/*   Updated: 2022/01/22 11:18:03 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	idx;
	size_t	size;

	if ((*needle == '\0'))
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	idx = 0;
	size = ft_strlen(needle);
	while (idx < len - size + 1 && (*(haystack + idx) != 0))
	{
		if (!ft_strncmp((char *)(haystack + idx), (char *)(needle), size))
			return ((char *)(haystack + idx));
		idx++;
	}
	if (haystack == NULL)
		return ((char *)haystack + *haystack);
	return (NULL);
}
