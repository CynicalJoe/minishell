#include "../../inc/minishell.h"

void	split_parsed_line(t_cmd_list *cmds, char *one_line)
{
	t_cursor	cur;

	if (!one_line)
		return ;
	if (*one_line == '\0')
		ps_last_addback(cmds, list_init(ft_strdup("")));
	else
	{
		
	}

}