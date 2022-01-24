# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <limits.h>
# include <stdbool.h>
# include <errno.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>ß

# include "../libft/libft.h"
// # include "../../inc_af/minishell.h"


// Global
t_shell	g_shell;
//		STRUCTS

// struct of shell
typedef struct s_shell
{
	char			**env;			// get the env for 
	char			*prompt;		// prompt for user to input commands
	t_cmd_container	cmd_container;
	int				exit_status;	// exit status --> make it a global variable?
	t_bool			in_exec;
	int				status;
	int				level;
}	t_shell;

// struct that contains the full command --> pre parsed
typedef struct s_cmd_container
{
	char	*line;
	size_t	read_index;
	t_cmd	**cmds;
	char	**tokens;
	char	*token;
}	t_cmd_container;

// struct to redirect ourput/intput
typedef struct s_shell_redir
{
	int		fd_backup;
	int		fd_replace;
}	t_shell_redir;

// struct for commands size, flags, args, etc....
typedef struct s_cmd
{
	size_t			index;			// index to move in command
	char			**tokens;
	char			**args;
	size_t			size;			// size of command
	struct s_cmd	*previous;
	struct s_cmd	*next;
	t_bool			piped;
	t_shell_redir	out;
	t_shell_redir	in;
}	t_cmd;

//			FUNCTIONS

// setline to prompt and get user input
void	set_line(t_cmd_container *cmd_container, char *line)
{
	free(cmd_container->line);
	cmd_container->line = line;
}

//			TOKENISE

// check the size of the cmd_container
size_t	get_cmds_size(t_cmd_container *cmd_container)
{
	size_t	size;

	if (cmd_container == NULL)
		return (0);
	size = 0;
	while (cmd_container->cmds[size] != NULL)
		size++;
	return (size);
}

// got to the next token
void	next_token(t_cmd_container *cmd_container)
{
	if (cmd_container->token = NULL)
		return ;
	cmd_container->tokens = ft_addstr_to_strarray(cmd_container->tokens, cmd_container->token, TRUE);	// check for the works of this function
	cmd_container->token = NULL;
}



int	main(int ac, char **av, char **env)
{
	t_shell			shell;
	t_cmd_container	*cmd_container;


	(void)av;
	shell = create_shell(env);
	// update shell level using export
	
	if (ac != 1)
		exit_shell(&shell, "minishell does not take any arguments.\n", 1);
	cmd_container = &shell.cmd_container;
	signal(SIGINT, ctrl_c_signal);
	signal(SIGQUIT, SIG_IGN);	// check SIG_IGN
	while (1)
	{
		set_line(cmd_container, readline(shell.prompt))		// prompt for the user
		if (cmd_container->line == NULL)
			exit_shell(&shell, "Bye :)", 0);
		if (ft_strlen(cmd_container->line) > 0)
		{
			add_history(cmd_container->line);
			if (!tokenise(cmd_container->line))		// parse and tokenise input if == 1 not good
				continue;
			process_cmds(&shell, cmd_container);	// execute commands parsed
		}
	}
	return (EXIT_SUCCESS);
}

