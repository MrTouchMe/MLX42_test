# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/22 23:48:14 by dgiurgev          #+#    #+#              #
#    Updated: 2024/03/23 00:07:29 by dgiurgev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		so_long
CFLAGS		=		-Wall -Wextra -g -fsanitize=address #-werror
CC			=		cc
SRC			=		src/main.c src/parse.c src/map_to_screen.c  src/keybinds.c src/load_png.c src/ft_hook.c src/ft_move.c
BIN			=		bin
OBJS		=		$(SRC:src/%.c=$(BIN)/%.o)
LIBFT		=		lib/libft/libft.a
PF			=		lib/ft_printf/libftprintf.a
GNL			=		lib/get_next_line/getnextline.a
COLOR_RESET	=		\033[0m
COLOR_CYAN	=		\033[36m
COLOR_GREEN	=		\033[32m
COLOR_RED	=		\033[31m
all:				$(NAME)
$(LIBFT):
					@cd lib/libft && make
$(PF):
					@cd lib/ft_printf && make
$(GNL):
					@cd lib/get_next_line && make

$(NAME):install_mlx $(LIBFT) $(PF) $(GNL) $(OBJS)
					@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L./lib/MLX42/build/ -lmlx42 -Iinclude -lglfw -L./lib/libft -lft -L./lib/get_next_line -lgetnextline
					@echo "$(COLOR_CYAN)SO_LONG Compilation completed: $(NAME)$(COLOR_RESET)"
lib/MLX42:
					@cd lib && git clone https://github.com/codam-coding-college/MLX42.git
					@cd lib/MLX42 && cmake -B build && cmake --build build -j4
install_mlx:		lib/MLX42
$(BIN)/%.o:			src/%.c
					@mkdir -p $(BIN)
					@$(CC) $(CFLAGS) -c $< -o $@
					@echo "$(COLOR_GREEN)SO_LONG Compilation completed: $@$(COLOR_RESET)"

clean:
					@cd lib/libft && make clean
					@cd lib/ft_printf && make clean
					@cd lib/get_next_line && make clean
					rm -f $(BIN)/*
					@echo "$(COLOR_RED)Cleanup completed.$(COLOR_RESET)"
fclean:				clean
					@rm -f $(NAME)
					@cd lib/libft && make fclean
					@cd lib/ft_printf && make fclean
					@cd lib/get_next_line && make fclean
					@echo "$(COLOR_RED)Removal completed.$(COLOR_RESET)"
re:					fclean install_mlx all
