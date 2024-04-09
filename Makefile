# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/22 23:48:14 by dgiurgev          #+#    #+#              #
#    Updated: 2024/04/09 16:34:29 by dgiurgev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		so_long
CFLAGS		=		-Wall -Wextra -Werror
CC			=		cc
SRC			=		src/main.c src/parse.c src/map_to_screen.c  src/keybinds.c src/keybinds_helper.c src/load_png.c src/load_assets.c src/ft_hook.c src/ft_move.c src/map_checker.c src/map_checker_helper.c src/exit.c src/enemy.c src/free.c
BIN			=		bin
OBJS		=		$(SRC:src/%.c=$(BIN)/%.o)
LIBFT		=		libft/libft.a
COLOR_RESET	=		\033[0m
COLOR_CYAN	=		\033[36m
COLOR_GREEN	=		\033[32m
COLOR_RED	=		\033[31m

all:				$(NAME)

$(LIBFT):
					@cd libft && make

$(NAME):install_mlx $(LIBFT) $(OBJS)
					@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L./MLX42/build/ -lmlx42 -Iinclude -lglfw -L./libft -lft
					@echo "$(COLOR_CYAN)SO_LONG Compilation completed: $(NAME)$(COLOR_RESET)"
MLX42:
					@git clone git@github.com:MrTouchMe/MLX42.git
					@cd MLX42 && cmake -B build && cmake --build build -j4

install_mlx:		MLX42

$(BIN)/%.o:			src/%.c
					@mkdir -p $(BIN)
					@$(CC) $(CFLAGS) -c $< -o $@
					@echo "$(COLOR_GREEN)SO_LONG Compilation completed: $@$(COLOR_RESET)"

clean:
					@cd libft && make clean
					@rm -f $(BIN)/*
					@echo "$(COLOR_RED)Cleanup completed.$(COLOR_RESET)"

fclean:				clean
					@rm -f $(NAME)
					@rm -rf $(BIN)
					@cd libft && make fclean
					@echo "$(COLOR_RED)Removal completed.$(COLOR_RESET)"
re:					fclean install_mlx all
