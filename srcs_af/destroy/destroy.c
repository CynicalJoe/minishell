#include "../../inc/minishell.h"

void	*destroy_shell(t_shell *shell)
{
	if (shell != NUL)
	{
		shell->env = ft_destroy_string_array(&shell->env);
		free(shell->prompt);
		shell->prompt = NULL;
		destroy_cmds(&shell->cmd_container);
	}
	return (NULL);
}
