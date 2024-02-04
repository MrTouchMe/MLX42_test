# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 07:37:24 by dgiurgev          #+#    #+#              #
#    Updated: 2024/02/04 05:51:32 by dgiurgev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		libft.a

CFLAGS		=		-Wall -Wextra -Werror

CC			=		cc

SRC			=		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
					ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
					ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
					ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
					ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
					ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
					ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
					ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
					ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

BIN			=		bin

OBJS		=		$(patsubst %.c,$(BIN)/%.o,$(SRC))

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
