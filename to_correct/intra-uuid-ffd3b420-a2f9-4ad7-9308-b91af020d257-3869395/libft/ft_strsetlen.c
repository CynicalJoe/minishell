/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsetlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 15:24:52 by afulmini          #+#    #+#             */
/*   Updated: 2022/01/22 11:22:13 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strsetlen(char **strs)
{
	int	cnt;

	cnt = 0;
	if (strs == NULL)
		return (0);
	if (*strs == NULL)
		return (0);
	while (strs[cnt])
		cnt++;
	return (cnt);
}
