/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 19:44:58 by lumugot           #+#    #+#             */
/*   Updated: 2026/08/05 12:10:24 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <string.h>

# define RESET	"\033[0m"
# define BOLD	"\033[1m"
# define ITAL	"\033[3m"

# define RED	"\033[;31m"
# define GREEN	"\033[;32m"
# define YELLOW	"\033[;33m"
# define BLUE	"\033[;34m"
# define GREY	"\033[90m"


# define EX00_NAME	"Add, Subtract and Scale"
# define EX01_NAME	"Linear Combination"
# define EX02_NAME	"Linear Interpolation"
# define EX03_NAME	"Dot Product"
# define EX04_NAME	"Norm"
# define EX05_NAME	"Cosine"
# define EX06_NAME	"Cross Product"
# define EX07_NAME	"Matrix Multiplication"
# define EX08_NAME	"Trace"
# define EX09_NAME	"Transpose"
# define EX10_NAME	"Row Echelon Form"
# define EX11_NAME	"Determinant"
# define EX12_NAME	"Inverse"
# define EX13_NAME	"Rank"

# define EX00_LABEL	GREEN "[ ex00 ]" RESET
# define EX01_LABEL	GREEN "[ ex01 ]" RESET
# define EX02_LABEL	GREEN "[ ex02 ]" RESET
# define EX03_LABEL	GREEN "[ ex03 ]" RESET
# define EX04_LABEL	GREEN "[ ex04 ]" RESET
# define EX05_LABEL	GREEN "[ ex05 ]" RESET
# define EX06_LABEL	GREEN "[ ex06 ]" RESET
# define EX07_LABEL	GREEN "[ ex07 ]" RESET
# define EX08_LABEL	GREEN "[ ex08 ]" RESET
# define EX09_LABEL	GREEN "[ ex09 ]" RESET
# define EX10_LABEL	GREEN "[ ex10 ]" RESET
# define EX11_LABEL	GREEN "[ ex11 ]" RESET
# define EX12_LABEL	GREEN "[ ex12 ]" RESET
# define EX13_LABEL	GREEN "[ ex13 ]" RESET

void	exercise_header(char *label, char *name);

float	ft_abs(float x);
float	ft_sqrt(float x);
float	ft_pow(float x, int n);

#endif
