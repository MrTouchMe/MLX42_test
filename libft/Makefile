# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 07:37:24 by dgiurgev          #+#    #+#              #
#    Updated: 2024/03/23 06:30:05 by dgiurgev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		libft.a

CFLAGS		=		-Wall -Wextra -Werror

CC			=		cc

SRC			=		src/ft_isalpha.c src/ft_isdigit.c src/ft_isalnum.c src/ft_isascii.c src/ft_isprint.c src/ft_strlen.c src/ft_memset.c src/ft_bzero.c src/ft_memcpy.c src/ft_memmove.c src/ft_strlcpy.c src/ft_strlcat.c src/ft_toupper.c src/ft_tolower.c src/ft_strchr.c src/ft_strrchr.c src/ft_strncmp.c src/ft_memchr.c src/ft_memcmp.c src/ft_strnstr.c src/ft_atoi.c src/ft_atol.c src/ft_calloc.c src/ft_strdup.c src/ft_substr.c src/ft_strjoin.c src/ft_strtrim.c src/ft_split.c src/ft_itoa.c src/ft_strmapi.c src/ft_striteri.c src/ft_putchar_fd.c src/ft_putstr_fd.c src/ft_putendl_fd.c src/ft_putnbr_fd.c src/ft_lstnew.c src/ft_lstadd_front.c src/ft_lstsize.c src/ft_lstlast.c src/ft_lstadd_back.c src/ft_lstdelone.c src/ft_lstclear.c src/ft_lstiter.c src/ft_lstmap.c src/ft_functions_printf.c src/ft_parse_printf.c src/ft_printf.c src/get_next_line.c src/get_next_line_utils.c

BIN			=		bin

OBJS		=		$(patsubst src/%.c,$(BIN)/%.o,$(SRC))

COLOR_RESET	=		\033[0m
COLOR_CYAN	=		\033[36m
COLOR_GREEN	=		\033[32m
COLOR_RED	=		\033[31m

all:				$(NAME)

$(NAME):			$(OBJS)
					@ar rcs $(NAME) $(OBJS)
					@echo "$(COLOR_CYAN)LIBFT Compilation completed: $(NAME)$(COLOR_RESET)"

$(BIN)/%.o:	src/%.c
					@mkdir -p $(BIN)
					@$(CC) $(CFLAGS) -c $< -o $@
					@echo "$(COLOR_GREEN)LIBFT Compilation completed: $@$(COLOR_RESET)"

clean:
					@rm -rf $(BIN)
					@echo "$(COLOR_RED)Cleanup completed.$(COLOR_RESET)"

fclean:				clean
					@rm -f $(NAME)
					@echo "$(COLOR_RED)Removal completed.$(COLOR_RESET)"

re:					fclean all

.PHONY:				all clean fclean re
