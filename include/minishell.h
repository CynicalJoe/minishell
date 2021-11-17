#ifndef MINISHELL_H
# define MINISHELL_H
# include "../srcs/libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_cmd
{
   char           **cmd; // path to cmd (if system) or name of the function + various arguments if provided
   char           *file; // is set to NULL if file is not needed, otherwhise is filename
   int            pipe; // bolean for pipe
   int            rdr; // 0 for no redirection, 1 for infile, 2 for outfile
   struct s_cmd   *next; // chained list; pointer to the next cmd

} t_cmd;

typedef struct s_mini
{
   char	*line; //line inputed by the user when prompted
   t_cmd *start;

} t_mini;

t_mini	*init_mini();

t_mini *get_prompt(t_mini *mini);

#endif