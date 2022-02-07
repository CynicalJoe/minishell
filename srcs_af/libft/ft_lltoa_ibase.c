/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:39:08 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/07 14:49:47 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lltoa_ibase(long long number, int base, bool uppercase)
{
	char	*res;

	res = ft_ulltoa_ibase((unsigned long long)number, base, uppercase);
	if (number >= 0)
		return (res);
	return (ft_append_str("-", res, FALSE, TRUE));
}
