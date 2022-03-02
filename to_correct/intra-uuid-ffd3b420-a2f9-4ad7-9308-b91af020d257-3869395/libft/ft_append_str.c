/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:11:28 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/01 10:12:13 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_append_str(char *s1, char *s2, bool frees1, bool frees2)
{
	char	*res;
	size_t	res_size;
	size_t	s1_len;

	res_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = ft_calloc(res_size, sizeof(char));
	if (!res)
		return (NULL);
	s1_len = ft_strcpy(s1, res);
	ft_strcpy(s2, &res[s1_len]);
	if (frees1)
		free((void *)s1);
	if (frees2)
		free((void *)s2);
	return (res);
}
