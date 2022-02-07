NAME = minishell_afulmini

CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -lreadline

SRCS = 	signals/signals.c \
		shell/create_env.c \
		shell/create.c \
		shell/destroy.c \
		shell/get_env_len.c \
		shell/prompt.c \
		shell/set_env.c \
		shell/unset_env.c \

LIBFT_PATH	= ./libft
INC_PATH 	= ./include
OBJ = $(SRCS:%.c=%.o)


$(NAME):	$(LIBFT_PATH)/libft.a $(INCLUDE) $(OBJS)

all:	$(NAME)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	@$(RM) $(OBJS)

fclean:	clean

re: fclean all 

.PHONY: all re clean fclean