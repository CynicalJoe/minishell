/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtournay <gtournay@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 13:34:36 by gtournay          #+#    #+#             */
/*   Updated: 2020/07/24 18:30:25 by gtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	get_size(unsigned int n)
{
	int	size;

	size = 1;
	while (n / 10 > 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

static int	get_temp(int n)
{
	unsigned int	temp;

	if (n < 0)
		temp = -n;
	else
		temp = n;
	return (temp);
}

char	*ft_itoa(int n)
{
	unsigned int	sign;
	unsigned int	temp;
	int				size;
	char			*res;

	size = 1;
	sign = 0;
	temp = get_temp(n);
	if (n < 0)
		sign = 1;
	size = get_size(temp);
	res = (char *)malloc(sizeof(char) * (size + sign + 1));
	if (!res)
		return (NULL);
	res[size + sign] = '\0';
	while (size)
	{
		res[size + sign - 1] = temp % 10 + '0';
		temp /= 10;
		size--;
	}
	if (sign == 1)
		res[0] = '-';
	return (res);
}
