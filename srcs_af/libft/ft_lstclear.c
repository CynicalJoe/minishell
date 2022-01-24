/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:41:38 by afulmini          #+#    #+#             */
/*   Updated: 2022/01/22 11:17:26 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (lst == NULL || *lst == NULL)
		return ;
	tmp = *lst;
	if (tmp->next == NULL)
		ft_lstdelone(tmp, del);
	else
	{
		while (tmp->next != NULL)
		{
			*lst = tmp;
			tmp = tmp->next;
			del((*lst)->content);
			free(*lst);
			*lst = NULL;
			if (tmp->next == NULL)
			{
				ft_lstdelone(tmp, del);
				return ;
			}
		}
	}
}
