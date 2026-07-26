# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/19 11:09:11 by lumugot           #+#    #+#              #
#    Updated: 2026/07/26 14:52:13 by lumugot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= matrix

CC		= clang

CFLAGS	= -Wall -Wextra -Werror -g

SRC		= srcs/main.c \
			srcs/vector.c \
			srcs/matrix.c \
			srcs/exercises/ex00.c \
			srcs/exercises/ex01.c \
			srcs/exercises/ex02.c \
			srcs/exercises/ex03.c \
			srcs/exercises/ex04.c \
			srcs/exercises/ex05.c \
			srcs/exercises/ex06.c \
			srcs/exercises/ex07.c \
			srcs/exercises/ex08.c

OBJ			= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -lm

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

run: all
	./matrix

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
