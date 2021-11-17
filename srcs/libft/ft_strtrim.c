/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtournay <gtournay@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 13:34:36 by gtournay          #+#    #+#             */
/*   Updated: 2020/09/11 10:42:48 by gtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	get_start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] && is_in_set(s1[i], set) == 1)
		i++;
	return (i);
}

static int	get_end(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1);
	i--;
	while (i && is_in_set(s1[i], set) == 1)
		i--;
	return ((int)i);
}

static char	*trimcpy(char const *s1, char *trim, int start, int end)
{
	int	i;

	i = 0;
	while (start <= end)
	{
		trim[i] = s1[start];
		i++;
		start++;
	}
	trim[i] = '\0';
	return (trim);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		start;
	int		end;

	if (!s1)
		return (0);
	start = get_start(s1, set);
	end = get_end(s1, set);
	if (end == 0)
	{
		trim = malloc(sizeof(s1));
		if (!trim)
			return (NULL);
		trimcpy(s1, trim, start, end);
		return (trim);
	}
	trim = (char *)malloc(sizeof(char) * ((end - start) + 2));
	if (!trim)
		return (NULL);
	trimcpy(s1, trim, start, end);
	return (trim);
}
