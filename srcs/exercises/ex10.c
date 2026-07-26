/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex10.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 15:21:29 by lumugot           #+#    #+#             */
/*   Updated: 2026/07/26 17:03:25 by lumugot          ###   ########.fr       */
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
				matrix->data[i][j] = fmaf(-f, matrix->data[p_row][i], matrix->data[i][j]);
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

	return (result);
}

void	ex10(void)
{

}
