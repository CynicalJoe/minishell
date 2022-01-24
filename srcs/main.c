#include "../include/minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_mini *mini;

	mini = init_mini();
	while (1)
	{
		get_prompt(mini);
		parse(mini);
		printf("%s\n",mini->line);
	}
	return (EXIT_SUCCESS);
}
