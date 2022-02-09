NAME = minishell_afulmini

CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

# NOTE - referring to M1 rosetta arch -86_64 brew readline lib
# ARCH := $(shell arch)
# GITUSER := $(USER)
# ifeq ($(GITUSER), runner)
# 	RDLN_LFLAGS	= -l readline -L/usr/local/opt/readline/lib 
# 	RDLN_INC	= -I/usr/local/opt/readline/include
# else ifeq ($(ARCH), i386)
# 	RDLN_LFLAGS	= -lreadline -L/usr/local/opt/readline/lib
# 	RDLN_INC	= -I/usr/local/opt/readline/include
# else ifeq ($(ARCH), arm64)
# 	RDLN_LFLAGS	= -l readline -L /opt/homebrew/opt/readline/lib
# 	RDLN_INC	= -I /opt/homebrew/opt/readline/include
# endif

RDLN_LFLAGS	= -lreadline # -L/usr/local/opt/readline/lib
RDLN_INC	= -I /usr/local/opt/readline/include

SRCS = 	signals/signals.c \
		shell/create_env.c \
		shell/create.c \
		shell/destroy.c \
		shell/prompt.c \
		shell/set_env.c \
		shell/unset_env.c \
		parser/all_cmds_filled.c \
		parser/check_and_give_token.c \
		parser/next_token.c \
		parser/quotes_closed.c \
		parser/realloc_cmds.c \
		parser/tokenise_pipe.c \
		parser/tokenise_quote.c \
		parser/tokenise_redir.c \
		parser/tokenise.c \
		builtin/cd.c \
		builtin/echo.c \
		builtin/env.c \
		builtin/export.c \
		builtin/get_builtin.c \
		builtin/pwd.c \
		builtin/unset.c \
		cmd/cmd_container.c \
		cmd/cmds.c \
		cmd/get_cmd_size.c \
		cmd/next_cmd.c \
		execute/check_path.c \
		execute/execute_command.c \
		execute/execute_program.c \
		execute/parse_cmd.c \
		execute/process_utils.c \
		redir/.......... \
		main.c \
		error.c 

LIBFT_PATH	= ./libft


LIBFT_DIR		= ./libft/
LIBFT_FLAGS		= -L./$(LIBFT_DIR) -lft
LIBFT_FILE		= $(LIBFT_DIR)libft.a

INCLUDE 	= ./include/minishell.h
OBJS = $(SRCS:.c=.o)

all:	$(NAME) $(LIBFT_FILE) $(OBJS)

$(NAME):	$(LIBFT_PATH)/libft.a $(INCLUDE) $(OBJS)
	@$(CC)									\
	$(CFLAGS)								\
	$(LIBFT_PATH)/libft.a					\
	$(INCLUDE)
	$(OBJS)									\
	-o $(NAME)

%.o:	%.c $(INCLUDE)
	@$(CC) $(CFLAGS) -I$(INC_DIR) $(RDLN_LFLAGS) $(RDLN_INC) -c $< -o $@

$(LIBFT_PATH)/libft.a:
	$(MAKE) -C $(LIBFT_PATH) bonus

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	@$(RM) $(OBJS)

fclean:	clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)

re: fclean all 

.PHONY: all re clean fclean