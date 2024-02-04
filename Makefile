NAME		=		so_long

CFLAGS		=		-Wall -Werror -Wextra

CC			=		cc

SRC			=		src/main.c src/animate.c src/image_utils.c

BIN			=		bin

OBJS		=		$(SRC:src/%c=$(BIN)/%o)

COLOR_RESET	=		\033[0m
COLOR_CYAN	=		\033[36m
COLOR_GREEN	=		\033[32m
COLOR_RED	=		\033[31m

$(NAME): 			install_mlx lib/libft/libft.a $(OBJS)
					@$(CC) -o $(NAME) $(OBJS) -L./lib/MLX42/build/ -lmlx42 -Iinclude -lglfw -L./lib/libft -lft
					@cd lib/libft && make && cd ../ft_printf && make && cd ../get_next_line && make
					@echo "$(COLOR_CYAN)SO_LONG Compilation completed: $(NAME)$(COLOR_RESET)"

lib/MLX42:
					@cd lib && git clone https://github.com/codam-coding-college/MLX42.git
					@cd lib/MLX42 && cmake -B build && cmake --build build -j4

install_mlx:		lib/MLX42

$(BIN)/%.o:	src/%.c
					@mkdir -p $(BIN)
					@$(CC) $(CFLAGS) -c $< -o $@
					@echo "$(COLOR_GREEN)SO_LONG Compilation completed: $@$(COLOR_RESET)"

all:				$(NAME)

clean:
					@rm -rf $(BIN) && cd lib/libft && rm -rf $(BIN) \
					&& cd ../ft_printf && rm -rf $(BIN) && cd ../get_next_line && rm -rf $(BIN) \
					@echo "$(COLOR_RED)Cleanup completed.$(COLOR_RESET)"

fclean:				clean
					@rm -f $(NAME)
					@echo "$(COLOR_RED)Removal completed.$(COLOR_RESET)"

re:					fclean install_mlx all
