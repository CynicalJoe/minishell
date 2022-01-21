/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:28:59 by afulmini          #+#    #+#             */
/*   Updated: 2021/11/30 09:48:27 by afulmini         ###   ########.fr       */
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

# include "../libft/libft.h"

typedef struct	s_shell
{
	char	**env;
	char	*prompt;
	int		exit_status;
	t_cmd	cmd_list;
}				t_shell;

typedef struct s_token
{
	char	*line;
	char	**tokens;
	char	*token;
	size_t	read_index;
	t_cmd	*cmds;
}				t_token;

typedef struct s_cmd
{
	size_t			index;
	char			**tokens;
	char			**args;
	size_t			size;
	struct s_cmd	*previous;
	struct s_cmd	*next;
	pid_t			pid;

}				t_cmd;

int	main(int ac, char **ac, char **env);

#endif
