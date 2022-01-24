//#include "../inc/minishel.h"

/* void	exit_shell(t_shell *shell, char *msg, int code)
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
} */

// -l readline -L/Users/afulmini/.brew/opt/readline/lib 
// -I/Users/afulmini/.brew/opt/readline/include

/* 
int	parsing(char *line)
{
	int	i;
	char	**sep;

	i = 0;
	*sep = NULL;
	while (*line)
	{
		if (*line != " ")
		{
			*sep[i] = *line;
			printf("%s\n", *sep[i]);
		}
		if (*line == " ")
				i++;
		printf("%d\n", i);
	}
	return (0);
} */


#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#include "../libft/libft.h"
#include "../inc_af/minishell.h"

int	g_exit_code = 0;

typedef struct s_args
{
	int		id;
	char	*cmd;
	struct s_args	*next;
}	t_args;


/* 
void	parse_line(char *line, t_args **cmds)
{
	t_args	**seperated;
	int		i;

	i = ft_strlen(line);
	seperated = cmds;
	printf("%d\n", i);
	seperated->cmd = line;
	printf("%s\n", (char *)seperated->cmd);
}
 */


t_args	*init()
{
	t_args	*args;

	args = malloc(sizeof(t_args));
	if (!args)
	{
		printf("no mallocin\n");
		return (NULL);
	}
	args->id = 0;
	args->cmd = NULL;
	return (args);
}

// Signal Handling

void	main_sig_handler(int signal)
{
	if (signal == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		g_exit_code = 1;
	}
	else if (signal == SIGQUIT)
		rl_on_new_line();
	rl_redisplay();
}

void	sigint_n_sigquit_handler(void (*sigfunction))
{
	signal(SIGINT, sigfunction);
	signal(SIGQUIT, sigfunction);
}

void	unexp_eof_sigint_handler(int signal)
{
	if (signal == SIGINT)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_exit_code = 1;
	}
}

/* char	**sh_process_env(int ac, char **av, char **env)
{
	char **ret;

	if (ac > 1 || av[1])

}
 */
void	eof_exit(char *line_read)
{
	if (!line_read)
	{
		ft_putendl_fd("exit\n", STDERR_FILENO);
		exit(EXIT_SUCCESS);
	}
}

void	eof_sig_handler(void)
{
	signal(SIGINT, unexp_eof_sigint_handler);
}


int	main(int ac, char **av, char **env)
{
	char	*line_read;
	char	**ft_env;
	t_args	*cmds;

	//ft_env = sh_process_env(ac, av, env);

	cmds = init();
	cmds->id = 0;
	cmds->cmd = "hello";
	while (1)
	{
		eof_sig_handler();
		line_read = readline("🐘 esh > ");
		//eof_exit(line_read);
		if (!ft_strcmp(line_read, "exit"))
		{
			printf("%s\n", line_read);
			break ;
		}
		//parse_line(line_read, &cmds);
		printf("%d\n", cmds->id);
		printf("%s\n", cmds->cmd);
		//free(cmds); 
	}
	return (EXIT_SUCCESS);
}