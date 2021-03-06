# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/11 16:52:24 by afulmini          #+#    #+#              #
#    Updated: 2022/02/17 09:20:05 by afulmini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 			=	gcc
CFLAGS 		=	-Wall -Wextra -Werror
NAME 		=	libft.a
SRCS 		=	ft_memset.c\
				ft_memcpy.c\
				ft_bzero.c\
				ft_memccpy.c\
				ft_memchr.c\
				ft_memmove.c\
				ft_memcmp.c\
				ft_strlen.c\
				ft_atoi.c\
				ft_atol.c\
				ft_strlcpy.c\
				ft_strcpy.c\
				ft_strchr.c\
				ft_strrchr.c\
				ft_strnstr.c\
				ft_strncmp.c\
				ft_strcmp.c\
				ft_isalpha.c\
				ft_isdigit.c\
				ft_isalnum.c\
				ft_isascii.c\
				ft_isprint.c\
				ft_ischarset.c\
				ft_iserror.c\
				ft_toupper.c\
				ft_tolower.c\
				ft_calloc.c\
				ft_strdup.c\
				ft_strndup.c\
				ft_substr.c\
				ft_strjoin.c\
				ft_strtrim.c\
				ft_split.c\
				ft_split_charset.c\
				ft_itoa.c\
				ft_strmapi.c\
				ft_putchar_fd.c\
				ft_putstr_fd.c\
				ft_putendl_fd.c\
				ft_putnbr_fd.c\
				ft_strlcat.c\
				ft_strsetlen.c\
				ft_strrnstr.c\
				ft_strchrset.c\
				ft_strrchrset.c\
				bubble_sort_strset.c\
				swap_char.c\
				strchrset_skip_bs.c\
				ft_strarray_length.c\
				ft_append_char_to_str.c\
				ft_addstr_to_strarray.c\
				ft_destroy_strarray.c\
				ft_append_str.c\
				ft_ull_ibase_len.c\
				ft_lltoa_ibase.c\
				ft_ulltoa_ibase.c\
				ft_sort_strarray.c\
				ft_copy_strarray.c\

OBJS		=	$(SRCS:.c=.o)

BONUS_SRCS	=	$(SRCS)\
				ft_lstnew.c\
				ft_lstadd_front.c\
				ft_lstsize.c\
				ft_lstlast.c\
				ft_lstadd_back.c\
				ft_lstdelone.c\
				ft_lstclear.c\
				ft_lstiter.c\
				ft_lstmap.c\

BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)

######################### Color #########################
GREEN		=	"\033[32m"
L_GREEN		=	"\033[1;32m"
RED			=	"\033[31m"
L_RED		=	"\033[1;31m"
RESET		=	"\033[0m"
BOLD		=	"\033[1m"
L_PUPLE		=	"\033[1;35m"
UP			=	"\033[A"
DOWN		=	"\033[B"
RIGHT		=	"\033[C"
LEFT		=	"\033[D"
CUT			=	"\033[K"
SAVE		=	"\033[s"
RESTORE		=	"\033[u"

########################## Rule ##########################
%.o				: %.c
				@$(CC) $(CFLAGS) -c $< -o $@
				@echo $(SAVE)$(CUT)$(BOLD)$(L_GREEN) Compiling with $(CFLAGS)...$(RESET)
				@echo $(CUT) $(GREEN)[$^] to [$@] $(RESET)
				@printf $(UP)$(UP)

all				: $(NAME)

$(NAME)			: $(OBJS) $(BONUS_OBJS)
				@ar rc $@ $(OBJS) $(BONUS_OBJS)
				@printf $(CUT) $(DOWN)
				@echo $(BOLD)$(L_PUPLE) ✨$@ linked!!📚$(RESET)

clean			:
				@rm -f $(OBJS) $(BONUS_OBJS)
				@echo $(L_RED) Remove OBJ files in libft 👋 $(RESET)

fclean			: clean
				@rm -f $(NAME)
				@echo $(RED) Remove $(NAME) 🔥 $(RESET)

re				: fclean all

bonus			: $(BONUS_OBJS)
				@ar cr $(NAME) $(BONUS_OBJS)
				@printf $(CUT) $(DOWN)
				@echo $(BOLD)$(L_PUPLE) ✨$(NAME) linked!!📚$(RESET)

.PHONY: all clean fclean re bonus