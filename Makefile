# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/19 11:09:11 by lumugot           #+#    #+#              #
#    Updated: 2026/07/19 11:48:26 by lumugot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= matrix

CC		= clang

CFLAGS	= -Wall -Wextra -Werror

SRC		= srcs/main.c \
			srcs/vector.c \
			srcs/matrix.c \
			srcs/exercises/ex00.c

OBJ			= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

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
