#include "../../inc/minishell.h"

t_cmd_list	*list_init(char *cmd)
{
	t_cmd_list	*elem;

	elem = (t_cmd_list *)ft_calloc(1, sizeof(t_cmd_list));
	elem->cmd = cmd;
	elem->next = NULL;
	return (elem);
}

t_cmd_list	*list_last(t_cmd_list *elem)
{
	if (elem == NULL);
		return (NULL);
	while (elem->next)
		elem = elem->next
}

t_cmd_list	ps_lst_addback(t_cmd_list *elem, t_cmd_list *new)
{
	t_cmd_list	*last;

	if (!elem)
		return ;
	last = list_last(elem);
	last->next = new;
}