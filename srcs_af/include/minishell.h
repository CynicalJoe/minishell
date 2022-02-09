/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:28:59 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/08 17:25:08 by afulmini         ###   ########.fr       */
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
# include<readline/readline.h>
# include<readline/history.h>

# include "../libft/libft.h"
// # include "../../inc_af/minishell.h"

// struct for commands size, flags, args, etc....
// 1 for each command
typedef struct s_cmd
{
	size_t			index;			// index to move in command
	char			**tokens;		// what type it is	
	char			**args;			// cmd and args for the commands to exec	
	// cmd->args[0] == cmd
	size_t			size;			// size of command
	struct s_cmd	*previous;		// link between the different cmds structs
	struct s_cmd	*next;			// link between the different cmds structs
	// piped flag defines the link to the next command
	int				piped;			// use int? or bool? TRUE or FALSE or 0 1 2
	// int				in_out;			// use for redirection
	pid_t			pid;
	int				pipe[2];
}	t_cmd;


// struct that contains the full command --> pre executed
typedef struct s_cmd_container
{
	char	*line;			// line read from the prompt
	size_t	read_index;		// index in the container struct
	t_cmd	**cmds;			// link to t_cmds
	char	**tokens;		// str array of the tokens extracted from the line inputed
	char	*token;			// each part that is tokenised (string with cmd and args)
}	t_cmd_container;


// struct of shell ==> if used as global is it justifiable?
typedef struct s_shell
{
	char			**env;			// get the env variables to use
	char			*prompt;		// prompt for user to input commands
	t_cmd_container	cmd_container;	// connect to container struct
	int				exit_status;	// exit status --> make it a global variable?
	bool			in_exec;		// use int instead of bool thus TRUE == 1 & FALSE == 0;
	int				level;			// update the shell level we are in --> each call of minishell += 1 level
}	t_shell;

// struct to redirect output/intput ?? 

// Global ??
//		STRUCTS
t_shell	*g_shell;


int	main(int ac, char **av, char **env);

bool	put_error(char *program, char *part1, char *part2);

// 			src/signals
// check for signals interpretation depending on the level and exec you are currently in
void	ctrl_backslash_signal(int sig);
void	ctrl_c_signal(int sig);

//			src/parser/
// parse & tokenize functions
int		quotes_closed(char *str);
int		all_cmds_filled(t_cmd_container *cmd_container);
void	check_and_give_token(t_cmd_container *cmd_container, char c);
void	tokenise_pipe(t_cmd_container *cmd_container);
void	tokenise_quote(t_cmd_container *cmd_container, char quote);
void	tokenise_redir(t_cmd_container *cmd_container, char redir);
bool	tokenise(t_cmd_container *cmd_container);

size_t	get_cmd_size(t_cmd_container *cmd_container);
char	**ft_append_str_to_str_array(char **strarray, char *str, bool free_array);
void	next_token(t_cmd_container *cmd_container);
t_cmd	**realloc_cmds(t_cmd_container *cmd_container);

//			src/shell/
// shell creator & destroyer
char	**create_env(char **default_env);
void	*destroy_shell(t_shell *shell);
t_shell create_shell(char **env);
void	update_prompt(t_shell *shell);
void	exit_shell(t_shell *shell, char*message, int exit_code);

// get and set env variables
size_t	get_env_len(t_shell *shell);
ssize_t	get_env_index(t_shell *shell, char *key);
char	*get_env_var(t_shell *shell, char *key);
void	set_env(t_shell	*shell, char *key, char *value, bool free_val);
void	unset_env_var(t_shell *shell, char *key);

//			src/cmd/
// cmd_container and cmd initialisation and destruction
void	init_container(t_cmd_container *cmd_container);
void	*destroy_cmd_container(t_cmd_container *cmd_container);

t_cmd	*create_cmd(size_t i, char **args);
void	*destroy_cmd(t_cmd *cmd);
size_t	get_cmd_size(t_cmd_container *cmd_container);		// get the size of the commands in the container
void	next_cmd(t_cmd_container *cmd_container);			// gets next command in the container struct

//			src/execute/ 		==> process commands before executing them

char	*processed_args(t_shell *shell, char *arg);
char	*get_processed_quote(t_shell *shell, char *args, size_t len, size_t *i);
char	*get_env_var_name(char *arg, size_t len, size_t *i);
char	*ft_append_env_to_str(t_shell *shell, char *str, char *key);


//			src/execute/
void	parse_cmd(t_shell *shell, t_cmd *cmd);
char	*get_program_path(t_shell *shell, char *program);
bool	check_if_exist(char *path, char *program);
char	*build_path(char *path, char *program);

//			 exec program
void	execute_command(t_shell *shell, t_cmd *cmd);
void	execute_program(t_shell *shell, char *path, t_cmd *cmd);

//			src/builtin/
// check builtin function list 
void	(*get_builtin(char *builtin_str))(t_shell *shell, char **cmd);
void	my_cd(t_shell *shell, char **cmd);
void	my_echo(t_shell *shell, char **cmd);
void	my_env(t_shell *shell, char **cmd);
void	my_pwd(t_shell *shell, char **args);
void	my_exit(t_shell *shell, char **args);
void	my_unset(t_shell *shell, char **cmd);
void	my_export(t_shell *shell, char **cmd);

// utils
int	ft_contains_char(char *str, char c);
ssize_t	ft_find_char(char *s, char c);



// TESTING
void	display_env_var(t_shell *shell);
void	display_cmd(t_cmd *cmd);
void	display_cmd_container(t_cmd_container *cmd_container);


#endif
