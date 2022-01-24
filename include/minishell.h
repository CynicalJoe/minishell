/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:28:59 by afulmini          #+#    #+#             */
/*   Updated: 2022/01/24 09:42:40 by afulmini         ###   ########.fr       */
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
	bool			in_exec;		// use int ?
	int				status;
	int				level;
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
}	t_cmd;


int	main(int ac, char **av, char **env);

// parse & tokenize functions
bool	all_cmds_filled(t_cmd_container *cmd_container);
void	check_and_give_token(t_cmd_container *cmd_container, char c);
void	tokenise_pipe(t_cmd_container *cmd_container);
void	tokenise_quote(t_cmd_container *cmd_container, char quote);
void	tokenise_redir(t_cmd_container *cmd_container, char redir);

void	next_token(t_cmd_container *cmd_container);
t_cmd	**realloc_cmds(t_cmd_container *cmd_container);

// shell creator & destroyer
char	**create_env(char **default);
void	*destroy_shell(t_shell *shell);
t_shell create_shell(char **env);


#endif
