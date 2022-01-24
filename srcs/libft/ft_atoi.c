/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtournay <gtournay@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 13:57:54 by gtournay          #+#    #+#             */
/*   Updated: 2020/09/14 12:50:11 by gtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == 32 || (9 <= c && c <= 13))
		return (1);
	else
		return (0);
}

static int	long_checker(const char *nptr, int i, int sign)
{
	long unsigned int	res;

	res = 0;
	while (nptr[i] && (48 <= nptr[i] && nptr[i] <= 57))
	{
		res = res * 10 + (nptr[i] - 48);
		i++;
	}
	if (!sign && res > 2147483647)
		return (-1);
	else if (sign && res > 2147483648)
		return (0);
	return ((int)res);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	while (nptr[i] && ft_isspace(nptr[i]))
		i++;
	if (nptr[i] && nptr[i] == '-')
	{
		i++;
		sign++;
	}
	else if (nptr[i] && nptr[i] == '+')
		i++;
	if (sign)
		return (-long_checker(nptr, i, sign));
	return (long_checker(nptr, i, sign));
}
