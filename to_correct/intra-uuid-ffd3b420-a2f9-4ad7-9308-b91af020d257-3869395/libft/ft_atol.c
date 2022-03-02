/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 10:05:26 by afulmini          #+#    #+#             */
/*   Updated: 2022/01/22 11:16:03 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*go_to_digit(char *str, int *sign)
{
	while ((*str <= 13 && *str >= 9) || *str == ' ')
		str++;
	if (*str == '-')
	{
		str++;
		*sign = -1;
	}
	else if (*str == '+')
		str++;
	return (str);
}

t_ll	ft_atol(const char *str)
{
	t_ull	num;
	int		sign;
	int		cnt;

	sign = 1;
	num = 0;
	cnt = 20;
	str = go_to_digit((char *)str, &sign);
	while (*str >= '0' && *str <= '9' && --cnt)
		num = 10 * num + (*str++ - '0');
	if (num > ULL_MAX || !cnt)
	{
		if (sign == 1)
			return (-1);
		else if (sign == -1 && num != (t_ull)ULL_MAX + 1)
			return (0);
	}
	return (sign * num);
}
