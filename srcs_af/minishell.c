#include "../inc/minishel.h"

void	exit_shell(t_shell *shell, char *msg, int code)
{
	if (msg != NULL)
	{
		ft_putstr_fd(1, msg);
	}
	destroy_shell(shell);
	exit(code);
}

void	*destroy_shell(t_shell *shell)
{
	if (shell != NULL)
	{
		shel->env = ft_destroy_string_array(&shell->env);
		free(shell->prompt);
		shell->prompt = NULL;
		destroy_cmd_list(&shell->cmd_list);
	}
	return (NULL);
}

void	*destroy_cmd_list(t_cmd *cmd_list)
{
	size_t	index;

	if (cmd_list != NULL)
	{
		free(cmd_list->line);
		cmd_list->line = NULL;
		cmd_list->read_index = 0;
		index = 0;
		while (index < get_cmd_size(cmd_list))
		{
			destroy_cmd(cmd_container->cmd);
			index++;
		}
		free(cmd_list)
	}
}

int main(int ac, char **av, char **env)
{
	t_shell			shell;
	t_token			*cmds;

	(void)av;
	shell = create_shell(env);
	if (ac != 1)
		return (ft_error());

	signal(SIGINT, )
	sigaction(SIGQUIT, SIG_IGN);
	while (1)
	{
		if (cmds->line == NULL)
			exit_shell(&shell, "Exiting!", 0);
		if (ft_strlen(cmds->line) > 0)
		{
			
		}
	}
	return (0);
}