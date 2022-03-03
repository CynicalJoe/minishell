/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:28:59 by afulmini          #+#    #+#             */
/*   Updated: 2022/03/03 16:14:01 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

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

// struct to redirect output/intput 
typedef struct s_redir
{
	int		fd;
	int		fd_replaced;
	char	*temp_file;
}	t_redir;

// struct for commands size, flags, args, etc....
// 1 for each command
typedef struct s_cmd
{
	size_t			index;
	char			**tokens;
	char			**args;
	size_t			size;
	struct s_cmd	*previous;
	struct s_cmd	*next;
	bool			piped;
	pid_t			pid;
	int				pipe[2];
	t_redir			out;
	t_redir			in;
}	t_cmd;

// struct that contains the full command --> pre executed
typedef struct s_cmd_container
{
	char	*line;
	size_t	read_index;
	t_cmd	**cmds;	
	char	**tokens;
	char	*token;
}	t_cmd_container;

// struct of shell ==> if used as global is it justifiable?
typedef struct s_shell
{
	char			**env;
	char			*prompt;
	t_cmd_container	cmd_container;
	int				exit_status;
	bool			in_exec;
	int				level;
	bool			double_out;
}	t_shell;

t_shell	*g_shell;

int		main(int ac, char **av, char **env);

bool	put_error(char *program, char *part1, char *part2);

// 			src/signals
// check for signals interpretations
void	ctrl_backslash_signal(int sig);
void	ctrl_c_signal(int sig);

//			src/parser/
// parse & tokenize functions
int		quotes_closed(char *str);
bool	all_cmds_filled(t_cmd_container *cmd_container);
void	check_and_give_token(t_cmd_container *cmd_container, char c);
void	tokenise_pipe(t_cmd_container *cmd_container);
void	tokenise_quote(t_cmd_container *cmd_container, char quote);
void	tokenise_redir(t_cmd_container *cmd_container, char redir);
bool	tokenise(t_cmd_container *cmd_container);

size_t	get_nbr_tokens(t_cmd *cmd);
size_t	get_cmd_size(t_cmd_container *cmd_container);
char	**ft_append_str_to_str_array(char **strarray, char *str,
			bool free_array);
void	next_token(t_cmd_container *cmd_container);
t_cmd	**realloc_cmds(t_cmd_container *cmd_container);

//			src/shell/
// shell creator & destroyer
char	**create_env(char **default_env);
void	*destroy_shell(t_shell *shell);
t_shell	create_shell(char **env);
t_shell	update_level(t_shell shell);
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
size_t	get_cmd_size(t_cmd_container *cmd_container);
void	next_cmd(t_cmd_container *cmd_container);

//			src/execute/ 		==> process commands before executing them
void	process_commands(t_shell *shell, t_cmd_container *cmd_container);
void	set_in_exec(t_shell *shell, bool state);

char	*get_processed_arg(t_shell *shell, char *arg);
char	*get_processed_quote(t_shell *shell, char *args, size_t len, size_t *i);
char	*get_env_var_name(char *arg, size_t len, size_t *i);
char	*ft_append_env_var_to_str(t_shell *shell, char *str, char *key);

//			src/execute/
void	parse_cmd(t_shell *shell, t_cmd *cmd);
char	*get_program_path(t_shell *shell, char *program);
bool	check_if_exist(char *path, char *program);
char	*build_path(char *path, char *program);
bool	is_redir(char *arg);

//			 exec program
void	execute_command(t_shell *shell, t_cmd *cmd);
void	execute_program(t_shell *shell, char *path, t_cmd *cmd);

//			src/redir/dispatch_redir.c
bool	dispatch_redir(t_shell *shell, t_cmd *cmd, size_t *arg_i);
bool	read_to_keyword(t_shell *shell, char *keyword, t_redir fds);
void	catch_keyword(char *keyword, int file_fd);
bool	file_redir(t_redir *shell_redir, char *file, int mode);
void	start_redir(t_redir *shell_redir, int replacement);
void	stop_redir(t_redir *shell_redir);
int		double_redir(t_redir fds, char *del);

//			src/redir/piping.c
t_cmd	*process_piped(t_shell *shell, t_cmd *cmd);

//			src/redir/redir_utils.c
char	*temp_file_gen(void);
int		output_redir_mode(char *redirection);

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
int		ft_contains_char(char *str, char c);
ssize_t	ft_find_char(char *s, char c);

// TESTING
void	display_env_var(t_shell *shell);
void	display_cmd(t_cmd *cmd);
void	display_cmd_container(t_cmd_container *cmd_container);

#endif
