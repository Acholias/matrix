/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex13.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 11:53:14 by lumugot           #+#    #+#             */
/*   Updated: 2026/08/05 12:17:32 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exercises.h"

static size_t	gauss_elimination(t_matrix *matrix)
{
	size_t	p_row;
	size_t	max_row;
	size_t	col;
	float	pivot;

	p_row = 0;
	col = 0;
	while (col < matrix->cols && p_row < matrix->rows)
	{
		max_row = find_pivot(matrix, p_row, col);
		if (ft_abs(matrix->data[max_row][col]) < EPSILON)
		{
			col++;
			continue ;
		}
		if (max_row != p_row)
			swap_rows(matrix, p_row, max_row);
		pivot = matrix->data[p_row][col];
		normalize_row(matrix, p_row, pivot);
		eliminate(matrix, p_row, col);
		p_row++;
		col++;
	}
	return (p_row);
}

static size_t	count_zero_rows(t_matrix *matrix)
{
	size_t	count;
	size_t	i;
	size_t	j;
	bool	is_zero;

	count = 0;
	i = 0;
	while (i < matrix->rows)
	{
		is_zero = true;
		j = 0;
		while (j < matrix->cols)
		{
			if (ft_abs(matrix->data[i][j]) > EPSILON)
			{
				is_zero = false;
				break ;
			}
			j++;
		}
		if (is_zero == false)
			count++;
		i++;
	}
	return (count);
}

size_t	rank(t_matrix *matrix)
{
	t_matrix	*result;
	size_t		r;

	result = from_mat(matrix->data, matrix->rows, matrix->cols);
	if (!result)
		return (0);
	gauss_elimination(result);
	r = count_zero_rows(result);
	free_mat(result);
	return (r);
}

void	ex13(t_cli *cli)
{
	size_t	result;

	exercise_header(EX13_LABEL, EX13_NAME);
	if (cli->count < 1)
	{
		printf(RED "Erreur" RESET " : ex13 attend 1 matrice\n");
		printf(GREY "Usage : ./matrix ex13 \"1,2;3,4\"\n" RESET);
		return ;
	}
	result = rank(cli->mats[0]);
	display_mat(cli->mats[0]);
	printf(GREY "rank = " RESET "%zu\n", result);
}
