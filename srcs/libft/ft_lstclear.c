/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtournay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 13:22:21 by gtournay          #+#    #+#             */
/*   Updated: 2020/09/12 12:21:13 by gtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*here;

	temp = *lst;
	while (temp)
	{
		here = temp;
		del(temp->content);
		temp = temp->next;
		free(here);
	}
	*lst = NULL;
}
