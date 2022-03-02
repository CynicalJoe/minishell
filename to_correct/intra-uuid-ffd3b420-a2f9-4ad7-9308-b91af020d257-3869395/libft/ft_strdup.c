/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:46:43 by afulmini          #+#    #+#             */
/*   Updated: 2022/01/22 11:18:00 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	idx;
	size_t	len;
	char	*tmp;

	idx = 0;
	len = ft_strlen(s1);
	tmp = (char *)ft_calloc(len + 1, sizeof(char));
	while (idx < len)
	{
		*(tmp + idx) = *(s1 + idx);
		idx++;
	}
	return (tmp);
}
