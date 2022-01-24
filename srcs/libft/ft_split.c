/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtournay <gtournay@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 13:34:36 by gtournay          #+#    #+#             */
/*   Updated: 2020/09/14 11:40:33 by gtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static unsigned int	word_count(char const *str, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

static unsigned int	letter_count(char const *str, char c, unsigned int i)
{
	unsigned int	letter;

	letter = 0;
	while (str[i] && str[i] != c)
	{
		letter++;
		i++;
	}
	return (letter);
}

static char	*word_copy(char const *str, char c, unsigned int *ptri
				, char *res)
{
	unsigned int	j;

	j = 0;
	while (str[*ptri] && str[*ptri] != c)
	{
		res[j] = str[*ptri];
		j++;
		(*ptri)++;
	}
	res[j] = '\0';
	return (res);
}

static char	**res_free(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char			**res;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	res = (char **)malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (j < word_count(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		res[j] = (char *)malloc((letter_count(s, c, i) + 1) * sizeof(char));
		if (!res[j])
			return (res_free(res));
		word_copy(s, c, &i, res[j]);
		j++;
	}
	res[j] = 0;
	return (res);
}
