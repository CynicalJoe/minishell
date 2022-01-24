NAME		= mini

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

LIB_DIR 	= libft/
LIB_FLAG	= -L./$(LIB_DIR) -lft	# link libft library to use it 
LIB_FILE	= $(LIB_DIR)libft.a

INC			= ./inc_af/

SRC			= srcs_af/main.c


all			:	$(LIB_FILE) 

# $(NAME)		:	$(LIB_FILE) $(OBJS)


$(LIB_FILE)	:
	@echo "Making library \n"
	@make -C $(LIB_DIR) bonus

.PHONY: all 