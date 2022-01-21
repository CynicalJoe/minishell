#include "../../inc/minishell.h"

t_shell create_shell(char **env)
{
	t_shell	shell;

	shell.emv = create_env(env);
	shell.prompt = NULL;
	set_env();
	update_prompt(&shell);
	init_cmds(&shell.cmds);
	shell.is_in_execution = FALSE;
	return(shell);
}

char	**create_env(char **default)
{
	char	**new_env;
	size_t	line_index;

	new_env = ft_calloc(ft_get_splitted_size(default_env) + 1, sizeof(char * ));
	if (new_env == NULL)
		return (NULL);
	line_index = 0;
	while (default_env[line_index] != NULL)
	{
		new_env[line_index] = ft_strdup(default_env[line_index]);
		line_index++;
	}
	new_env[line_index] = NULL;
	return (new_env);
}
