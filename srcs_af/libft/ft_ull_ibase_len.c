/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ull_ibase_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:36:28 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/07 14:38:07 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_ull_ibase_len(unsigned long long number, int ibase)
{
	size_t	res;

	res = 0;
	while (number != 0)
	{
		number /= ibase;
		res++;
	}
	return (res);
}
