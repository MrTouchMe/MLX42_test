# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/25 16:54:44 by dgiurgev          #+#    #+#              #
#    Updated: 2024/02/04 05:50:21 by dgiurgev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		get_next_line.a

CFLAGS		=		-Wall -Wextra -Werror -D BUFFER_SIZE=42

CC			=		cc

SRC			=		src/get_next_line.c src/get_next_line_utils.c

BIN			=		bin

OBJS		=		$(SRC:src/%c=$(BIN)/%o)

COLOR_RESET	=		\033[0m
COLOR_CYAN	=		\033[36m
COLOR_GREEN	=		\033[32m
COLOR_RED	=		\033[31m

all:				$(NAME)

$(NAME):			$(OBJS)
					@ar rcs $(NAME) $(OBJS)
					@echo "$(COLOR_CYAN)GET_NEXT_LINE Compilation completed: $(NAME)$(COLOR_RESET)"

$(BIN)/%.o:	src/%.c
					@mkdir -p $(BIN)
					@$(CC) $(CFLAGS) -c $< -o $@
					@echo "$(COLOR_GREEN)GET_NEXT_LINE Compilation completed: $@$(COLOR_RESET)"

clean:
					@rm -rf $(BIN)
					@echo "$(COLOR_RED)Cleanup completed.$(COLOR_RESET)"

fclean:				clean
					@rm -f $(NAME)
					@echo "$(COLOR_RED)Removal completed.$(COLOR_RESET)"

re:					fclean all

.PHONY:				all clean fclean re
