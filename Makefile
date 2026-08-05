# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/19 11:09:11 by lumugot           #+#    #+#              #
#    Updated: 2026/08/05 12:24:54 by lumugot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= matrix

CC		= clang

CFLAGS	= -Wall -Wextra -Werror -g

SRC		= srcs/main.c \
			srcs/vector.c \
			srcs/matrix.c \
			srcs/cli.c \
			srcs/display.c \
			srcs/utils.c \
			srcs/exercises/ex00.c \
			srcs/exercises/ex01.c \
			srcs/exercises/ex02.c \
			srcs/exercises/ex03.c \
			srcs/exercises/ex04.c \
			srcs/exercises/ex05.c \
			srcs/exercises/ex06.c \
			srcs/exercises/ex07.c \
			srcs/exercises/ex08.c \
			srcs/exercises/ex09.c \
			srcs/exercises/ex10.c \
			srcs/exercises/ex11.c \
			srcs/exercises/ex12.c \
			srcs/exercises/ex13.c

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

test: all
	@./matrix ex00 "0,0" "0,0" && \
	./matrix ex00 "1,0" "0,1" && \
	./matrix ex00 "1,1" "1,1" && \
	./matrix ex00 "21,21" "21,21" && \
	./matrix ex00 "-21,21" "21,-21" && \
	./matrix ex00 "0,1,2,3,4,5,6,7,8,9" "9,8,7,6,5,4,3,2,1,0" && \
	./matrix ex00 "0,0;0,0" "0,0;0,0" && \
	./matrix ex00 "1,0;0,1" "0,0;0,0" && \
	./matrix ex00 "1,1;1,1" "1,1;1,1" && \
	./matrix ex00 "21,21;21,21" "21,21;21,21" && \
	./matrix ex00 "0,0" "0,0" -s 1 && \
	./matrix ex00 "1,0" "0,1" -s 1 && \
	./matrix ex00 "1,1" "1,1" -s 2 && \
	./matrix ex00 "21,21" "21,21" -s 2 && \
	./matrix ex00 "42,42" "0,0" -s 0.5 && \
	./matrix ex00 "0,0;0,0" "0,0;0,0" -s 0 && \
	./matrix ex00 "1,0;0,1" "0,0;0,0" -s 1 && \
	./matrix ex00 "1,2;3,4" "0,0;0,0" -s 2 && \
	./matrix ex00 "21,21;21,21" "0,0;0,0" -s 0.5 && \
	./matrix ex01 "-42,42" -s -1 && \
	./matrix ex01 "-42" "-42" "-42" -s -1,1,0 && \
	./matrix ex01 "-42,42" "1,3" "10,20" -s 1,-10,-1 && \
	./matrix ex01 "-42,100,-69.5" "1,3,5" -s 1,-10 && \
	./matrix ex02 "0" "1" -s 0 && \
	./matrix ex02 "0" "1" -s 1 && \
	./matrix ex02 "0" "42" -s 0.5 && \
	./matrix ex02 "-42" "42" -s 0.5 && \
	./matrix ex02 "-42,42" "42,-42" -s 0.5 && \
	./matrix ex03 "0,0" "0,0" && \
	./matrix ex03 "1,0" "0,0" && \
	./matrix ex03 "1,0" "1,0" && \
	./matrix ex03 "1,0" "0,1" && \
	./matrix ex03 "1,1" "1,1" && \
	./matrix ex03 "4,2" "2,1" && \
	./matrix ex04 "0" && \
	./matrix ex04 "1" && \
	./matrix ex04 "0,0" && \
	./matrix ex04 "1,0" && \
	./matrix ex04 "2,1" && \
	./matrix ex04 "4,2" && \
	./matrix ex04 "-4,-2" && \
	./matrix ex05 "1,0" "0,1" && \
	./matrix ex05 "8,7" "3,2" && \
	./matrix ex05 "1,1" "1,1" && \
	./matrix ex05 "4,2" "1,1" && \
	./matrix ex05 "-7,3" "6,4" && \
	./matrix ex06 "0,0,0" "0,0,0" && \
	./matrix ex06 "1,0,0" "0,0,0" && \
	./matrix ex06 "1,0,0" "0,1,0" && \
	./matrix ex06 "8,7,-4" "3,2,1" && \
	./matrix ex06 "1,1,1" "0,0,0" && \
	./matrix ex06 "1,1,1" "1,1,1" && \
	./matrix ex07 "0,0;0,0" "0,0" && \
	./matrix ex07 "1,0;0,1" "0,0" && \
	./matrix ex07 "1,1;1,1" "4,2" && \
	./matrix ex07 "2,0;0,2" "2,1" && \
	./matrix ex07 "0.5,0;0,0.5" "4,2" && \
	./matrix ex08 "0,0;0,0" && \
	./matrix ex08 "1,0;0,1" && \
	./matrix ex08 "1,2;3,4" && \
	./matrix ex08 "8,-7;4,2" && \
	./matrix ex08 "1,0,0;0,1,0;0,0,1" && \
	./matrix ex09 "0,0;0,0" && \
	./matrix ex09 "1,0;0,1" && \
	./matrix ex09 "1,2;3,4" && \
	./matrix ex09 "1,0,0;0,1,0;0,0,1" && \
	./matrix ex09 "1,2;3,4;5,6" && \
	./matrix ex10 "0,0;0,0" && \
	./matrix ex10 "1,0;0,1" && \
	./matrix ex10 "4,2;2,1" && \
	./matrix ex10 "-7,2;4,8" && \
	./matrix ex10 "1,2;4,8" && \
	./matrix ex11 "0,0;0,0" && \
	./matrix ex11 "1,0;0,1" && \
	./matrix ex11 "2,0;0,2" && \
	./matrix ex11 "1,1;1,1" && \
	./matrix ex11 "0,1;1,0" && \
	./matrix ex11 "1,2;3,4" && \
	./matrix ex11 "-7,5;4,6" && \
	./matrix ex11 "1,0,0;0,1,0;0,0,1" && \
	./matrix ex12 "1,0;0,1" && \
	./matrix ex12 "2,0;0,2" && \
	./matrix ex12 "0.5,0;0,0.5" && \
	./matrix ex12 "0,1;1,0" && \
	./matrix ex12 "1,2;3,4" && \
	./matrix ex12 "1,0,0;0,1,0;0,0,1" && \
	./matrix ex12 "1,1;1,1" && \
	./matrix ex13 "0,0;0,0" && \
	./matrix ex13 "1,0;0,1" && \
	./matrix ex13 "2,0;0,2" && \
	./matrix ex13 "1,1;1,1" && \
	./matrix ex13 "0,1;1,0" && \
	./matrix ex13 "1,2;3,4" && \
	./matrix ex13 "-7,5;4,6" && \
	./matrix ex13 "1,0,0;0,1,0;0,0,1"

.PHONY: all clean fclean re test

