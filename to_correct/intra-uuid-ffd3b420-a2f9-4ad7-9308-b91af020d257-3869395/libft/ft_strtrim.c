/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:00:38 by afulmini          #+#    #+#             */
/*   Updated: 2022/01/22 11:18:04 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cmpchr(char s, char const *set)
{
	int	idx;

	idx = 0;
	while (*(set + idx))
	{
		if (*(set + idx) == s)
			return (1);
		idx++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		idx;
	int		len;

	if (s1 == 0 || set == 0)
		return (NULL);
	len = ft_strlen(s1);
	if (len > 1)
		len--;
	idx = 0;
	while (cmpchr(*(s1 + idx), set) && idx < len)
		idx++;
	while (cmpchr(*(s1 + len), set) && len > 0)
		len--;
	if (idx > len)
	{
		str = ft_strdup("");
		return (str);
	}
	str = (char *)ft_calloc(len - idx + 2, sizeof(char));
	ft_memcpy(str, s1 + idx, len - idx + 1);
	return (str);
}
