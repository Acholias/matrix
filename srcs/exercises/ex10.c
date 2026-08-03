/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex10.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 15:21:29 by lumugot           #+#    #+#             */
/*   Updated: 2026/08/03 12:08:48 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exercises.h"

// Swap deux lignes d'une matrice
static void	swap_rows(t_matrix *matrix, size_t a, size_t b)
{
	float	*temp;

	temp = matrix->data[a];
	matrix->data[a] = matrix->data[b];
	matrix->data[b] = temp;
}

// Normalize une ligne en divisant chaque élément par le pivot (après l'opération le pivot = 1)
static void	normalize_row(t_matrix *matrix, size_t row, float p)
{
	size_t	index;

	index = 0;
	while (index < matrix->cols)
	{
		matrix->data[row][index] /= p;
		index++;
	}
}

static void	eliminate(t_matrix *matrix, size_t p_row, size_t col)
{
	float	f;
	size_t	i;
	size_t	j;

	i = 0;
	while (i < matrix->rows)
	{
		if (i != p_row && fabsf(matrix->data[i][col]) > EPSILON)
		{
			f = matrix->data[i][col];
			j = 0;
			while (j < matrix->cols)
			{
				matrix->data[i][j] = fmaf(-f, matrix->data[p_row][j], matrix->data[i][j]);
				j++;
			}
		}
		i++;
	}
}

// Algorithme élimination de Gauss-Jordan
t_matrix	*row_echelon(t_matrix *matrix)
{
	t_matrix	*result;
	size_t		p_row;
	size_t		max_row;
	size_t		col;
	size_t		index;

	result = from_mat(matrix->data, matrix->rows, matrix->cols);
	if (!result)
		return (NULL);
	p_row = 0;
	col = 0;
	while (col < result->cols && p_row < result->rows)
	{
		max_row = p_row;
		index = p_row + 1;
		while (index < result->rows)
		{
			if (fabsf(result->data[index][col]) > fabsf(result->data[max_row][col]))
				max_row = index;
			index++;
		}
		if (fabsf(result->data[max_row][col]) < EPSILON)
		{
			col++;
			continue ;
		}
		swap_rows(result, p_row, max_row);
		normalize_row(result, p_row, result->data[p_row][col]);
		eliminate(result, p_row, col);
		p_row++;
		col++;
	}
	return (result);
}

void	ex10(t_cli *cli)
{
	t_matrix	*result;

	exercise_header(EX10_LABEL, EX10_NAME);
	if (cli->count < 1)
	{
		printf(RED "Erreur" RESET " : ex10 attend 1 matrice\n");
		printf(GREY "Usage : ./matrix ex10 \"1,2;3,4\"\n" RESET);
		return ;
	}
	result = row_echelon(cli->mats[0]);
	display_mat(cli->mats[0]);
	printf(GREY "row echelon =\n" RESET);
	display_mat(result);
	free_mat(result);
}
