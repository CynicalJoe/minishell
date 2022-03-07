NAME			=	minishell

GREEN			=	"\033[32m"
L_GREEN			=	"\033[1;32m"
RED				=	"\033[31m"
L_RED			=	"\033[1;31m"
RESET			=	"\033[0m"
BOLD			=	"\033[1m"
L_PUPLE			=	"\033[1;35m"
UP				=	"\033[A"
DOWN			=	"\033[B"
RIGHT			=	"\033[C"
LEFT			=	"\033[D"
CUT				=	"\033[K"
SAVE			=	"\033[s"
RESTORE			=	"\033[u"

GCC				=	gcc
RM				=	rm -rf
CFLAGS			=	-Wall -Wextra -Werror -g
LIBFT_PATH		=	./libft
INCLUDES_PATH	=	./include
INCLUDES		= 	./include/minishell.h

-include		sources.mk

OBJS 				=	$(SOURCES:.c=.o)

BREW_PATH			=	/usr/local/opt
BREW_INCLUDES_PATH	=	$(BREW_PATH)/readline/include
#READLINE_PATH		=	$(BREW_INCLUDES_PATH)

all		: $(NAME)

$(LIBFT_PATH)/libft.a:
	$(MAKE) -C $(LIBFT_PATH)

$(NAME)	: $(LIBFT_PATH)/libft.a $(INCLUDES) $(OBJS)
		@$(GCC) $(CFLAGS) $(LIBFT_PATH)/libft.a \
		-L $(BREW_PATH)/readline/lib -lreadline -I $(INCLUDES) -I $(BREW_INCLUDES_PATH) $(OBJS) -o $(NAME)
		@echo $(BOLD)$(L_PUPLE) ✨$@ created!! $(RESET)

#  -lreadline -L /usr/local/opt/readline/lib -I /usr/local/opt/readline/include
#	Clean	
linux	:	$(OBJS)
			$(MAKE) -C $(LIBFT_PATH)
			$(GCC) $(CFLAGS) $(OBJS) -o minishell libft/libft.a -lreadline

clean	:
		$(MAKE) -C $(LIBFT_PATH) clean
		@$(RM) $(OBJS)
		@echo $(L_RED) Cleaning all .o in project and libraries. $(RESET)

#	Full Clean
fclean	: clean
		$(MAKE) -C $(LIBFT_PATH) fclean
		@$(RM) $(NAME)
		@echo $(L_RED) Cleaning compiled program $(NAME). $(RESET)

#	Recompile
re		: fclean all

.PHONY:	all clean fclean re

