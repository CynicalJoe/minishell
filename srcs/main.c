#include "../include/minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_mini *mini;

	mini = init_mini();
	get_prompt(mini);
	printf("%s\n",mini->line);
	return (0);
}
