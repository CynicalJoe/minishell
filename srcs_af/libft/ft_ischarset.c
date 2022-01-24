/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischarset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:50:18 by afulmini          #+#    #+#             */
/*   Updated: 2022/01/22 16:50:20 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_charset(char c, char *charset)
{
	if (!charset)
		return (0);
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}
