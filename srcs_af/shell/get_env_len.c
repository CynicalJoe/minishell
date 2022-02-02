#include "../include/minishell.h"

size_t	get_env_len(t_shell *shell)
{
	return (ft_strarray_length(shell->env));
}
