#include "../../inc/minishell.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)malloc(sizeof(unsigned char) * size * count);
	if (str == 0)
	{
		ft_putendl_fd("Error while allocation", 2);
		exit(EXIT_FAILURE);
	}
	while (i < count * size)
	{
		*(str + i) = 0;
		i++;
	}
	return (str);
}

int	list_size(t_cmd_list *cmd)
{
	int size;

	size = 0;
	while (cmd)
	{
		size++;
		cmd = cmd->next;
	}
	return (size);
}

void	parse_line_main(t_cmd_list **cmd_list, char *line, char *one)
{
	t_cmd	*cmds;	// command struct to which send the commands parsed

	// read the prompt and check for errors	

}