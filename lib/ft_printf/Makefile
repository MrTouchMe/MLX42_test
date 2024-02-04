# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 13:15:05 by dgiurgev          #+#    #+#              #
#    Updated: 2024/02/04 05:51:02 by dgiurgev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		libftprintf.a

CFLAGS		=		-Wall -Wextra -Werror

CC			=		cc

SRC			=		src/ft_printf.c src/ft_parse.c src/ft_functions.c

BIN			=		bin

OBJS		=		$(SRC:src/%c=$(BIN)/%o)

COLOR_RESET	=		\033[0m
COLOR_CYAN	=		\033[36m
COLOR_GREEN	=		\033[32m
COLOR_RED	=		\033[31m

all:				$(NAME)

$(NAME):			$(OBJS)
					@ar rcs $(NAME) $(OBJS)
					@echo "$(COLOR_CYAN)FT_PRINTF Compilation completed: $(NAME)$(COLOR_RESET)"

$(BIN)/%.o:	src/%.c
					@mkdir -p $(BIN)
					@$(CC) $(CFLAGS) -c $< -o $@
					@echo "$(COLOR_GREEN)FT_PRINTF Compilation completed: $@$(COLOR_RESET)"

clean:
					@rm -rf $(BIN)
					@echo "$(COLOR_RED)Cleanup completed.$(COLOR_RESET)"

fclean:				clean
					@rm -f $(NAME)
					@echo "$(COLOR_RED)Removal completed.$(COLOR_RESET)"

re:					fclean all

.PHONY:				all clean fclean re
