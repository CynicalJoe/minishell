/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:28:59 by afulmini          #+#    #+#             */
/*   Updated: 2022/01/24 11:53:46 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define WHITE	"\033[0m"
# define RED	"\033[0;31m"
# define BRED	"\033[1;31m"
# define GREEN	"\033[0;32m"
# define BGREEN	"\033[1;32m"
# define BLUE	"\033[0;34m"
# define BBLUE	"\033[1;34m"
# define CYAN	"\033[0;36m"
# define BCYAN	"\033[1;36m"
# define FAILURE -1
# define TRUE 1
# define SUCCESS 0
# define FALSE 0

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
# include <sys/types.h>
# include <fcntl.h>

# include "../libft/libft.h"
// # include "../../inc_af/minishell.h"


// Global ??
//		STRUCTS

// struct of shell
typedef struct s_shell
{
	char			**env;			// get the env for 
	char			*prompt;		// prompt for user to input commands
	t_cmd_container	cmd_container;	// connect to container struct
	int				exit_status;	// exit status --> make it a global variable?
	int				in_exec;		// use int instead of bool thus TRUE == 1 & FALSE == 0;
	int				level;			// update the shell level we are in
}	t_shell;

// struct that contains the full command --> pre executed
typedef struct s_cmd_container
{
	char	*line;			// line read from the prompt
	size_t	read_index;		// index in the container struct
	t_cmd	**cmds;			// link to t_cmds
	char	**tokens;		
	char	*token;			// each part that is tokenised (string with cmd and args)
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
	char			**tokens;		// what type it is
	char			**args;			// args
	size_t			size;			// size of command
	struct s_cmd	*previous;
	struct s_cmd	*next;
	bool			piped;			// use int? 	
	t_shell_redir	out;
	t_shell_redir	in;
	pid_t			pid;
	int				pipe[2];
}	t_cmd;


int	main(int ac, char **av, char **env);

// parse & tokenize functions
int		quotes_closed(char *str);
int		all_cmds_filled(t_cmd_container *cmd_container);
void	check_and_give_token(t_cmd_container *cmd_container, char c);
void	tokenise_pipe(t_cmd_container *cmd_container);
void	tokenise_quote(t_cmd_container *cmd_container, char quote);
void	tokenise_redir(t_cmd_container *cmd_container, char redir);
int		tokenise(t_cmd_container *cmd_container);

void	next_token(t_cmd_container *cmd_container);
t_cmd	**realloc_cmds(t_cmd_container *cmd_container);

// shell creator & destroyer
char	**create_env(char **default_env);
void	*destroy_shell(t_shell *shell);
t_shell create_shell(char **env);

// get and set env variables
ssize_t	get_env_index(t_shell *shell, char *key);
char	*get_env_var(t_shell *shell, char *key);
void	set_env(t_shell	*shell, char *key, char *value, int free_val);

// cmd_container and cmd initialisation and destruction
void	init_container(t_cmd_container *cmd_container);
void	*destroy_cmd_container(t_cmd_container *cmd_container);

t_cmd	*create_cmd(size_t i, char **args);
void	destroy_cmd(t_cmd *cmd);
size_t	get_cmds_size(t_cmd_container *cmd_container);


#endif
