NAME			=	minishell

GCC				=	gcc
RM				=	rm -rf
CFLAGS			=	-Wall -Wextra -Werror
LIBFT_PATH		=	./libft
INCLUDES_PATH	=	./include
INCLUDES		= 	./include/minishell.h

-include		sources.mk

OBJS 				=	$(SOURCES:.c=.o)

BREW_PATH			=	/usr/local/opt
BREW_INCLUDES_PATH	=	$(BREW_PATH)/readline/include

all: $(NAME)

%.o:	%.c $(INCLUDES)
	$(GCC) $(CFLAGS) -I $(INCLUDES) -I $(BREW_INCLUDES_PATH) \
	-D READLINE_PATH=\"$(BREW_INCLUDES_PATH)/readline/readline.h\" \
	-D HISTORY_PATH=\"$(BREW_INCLUDES_PATH)/readline/history.h\" \
	-c $< -o $@

$(NAME): $(LIBFT_PATH)/libft.a $(INCLUDES) $(OBJS)
	$(GCC) $(CFLAGS) $(LIBFT_PATH)/libft.a \
	-L $(BREW_PATH)/readline/lib -lreadline -I $(INCLUDES) -I $(BREW_INCLUDES_PATH) $(OBJS) -o $(NAME)

$(LIBFT_PATH)/libft.a:
	$(MAKE) -C $(LIBFT_PATH)

#  -lreadline -L /usr/local/opt/readline/lib -I /usr/local/opt/readline/include
#	Clean	
clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	@$(RM) $(OBJS)
	@printf "$(NAME) Cleaning all .o in project and libraries.\n"

#	Full Clean
fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)
	@printf "$(NAME) Cleaning compiled programs $(NAME).\n"

#	Recompile
re:		fclean all

.PHONY:	all clean fclean re

