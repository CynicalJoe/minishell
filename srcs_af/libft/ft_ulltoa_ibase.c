/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_ibase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:43:17 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/07 14:52:52 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_toupper(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		s[i] = ft_toupper(s[i]);
		i++;
	}
	return (s);
}

char	*fill_res(unsigned long long number, int ibase, char *res, int len)
{
	while (number != 0)
	{
		if (number % ibase < 10)
			res[len - 1] = (number % ibase) + 48;
		else
			res[len - 1] = (number % ibase) + 87;
		number /= ibase;
		len--;
	}
	return (res);
}

char	*ft_ulltoa_ibase(unsigned long long number, int ibase, bool uppercase)
{
	char	*res;
	int		len;

	len = 0;
	res = 0;
	if (number == 0)
		return (ft_strdup("0"));
	len = ft_ull_ibase_len(number, ibase);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	res[len] = '\0';
	res = fill_res(number, ibase, res, len);
	if (uppercase)
		res = ft_str_toupper(res);
	return (res);
}
