/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:55:59 by afulmini          #+#    #+#             */
/*   Updated: 2022/01/22 11:17:31 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*))
{
	t_list	*newlst;
	t_list	*root_newlst;

	if (lst == NULL)
		return (NULL);
	newlst = ft_lstnew(f(lst->content));
	if (!newlst)
		return (NULL);
	root_newlst = newlst;
	while (lst->next != NULL)
	{
		newlst->next = ft_lstnew(f(lst->next->content));
		if (!newlst->next)
		{
			ft_lstclear(&root_newlst, del);
			return (NULL);
		}
		if (lst->next != NULL)
			lst = lst->next;
		newlst = newlst->next;
	}
	return (root_newlst);
}
