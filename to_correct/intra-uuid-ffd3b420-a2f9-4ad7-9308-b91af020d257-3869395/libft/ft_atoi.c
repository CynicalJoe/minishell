/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:16:22 by afulmini          #+#    #+#             */
/*   Updated: 2022/01/22 11:15:54 by afulmini         ###   ########.fr       */
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

int	ft_atoi(const char *str)
{
	unsigned long long	num;
	int					sign;
	int					cnt;

	sign = 1;
	num = 0;
	cnt = 20;
	str = go_to_digit((char *)str, &sign);
	while (*str >= '0' && *str <= '9' && --cnt)
		num = 10 * num + (*str++ - '0');
	if (num > 9223372036854775807 || !cnt)
	{
		if (sign == 1)
			return (-1);
		else if (sign == -1 && num != 9223372036854775808ULL)
			return (0);
	}
	return (sign * num);
}
