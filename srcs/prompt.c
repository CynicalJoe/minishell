#include "../include/minishell.h"

t_mini *get_prompt(t_mini *mini)
{
	if (mini->line)
	{	
		free(mini->line);
		mini->line = NULL;
	}
	mini->line = readline("minishell: ");
	if (mini->line && *mini->line)
		add_history(mini->line);
	return (mini);
}