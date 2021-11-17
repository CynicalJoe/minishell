#include "../include/minishell.h"

t_mini	*init_mini()
{
	t_mini *mini;

	mini = malloc(sizeof(t_mini));
	if (!mini)
		return (NULL);
	mini->line = NULL;
	return (mini);
}