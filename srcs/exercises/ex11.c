/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex11.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 12:11:43 by lumugot           #+#    #+#             */
/*   Updated: 2026/08/05 12:17:38 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exercises.h"

int	find_pivot(t_matrix *matrix, size_t p_row, size_t col)
{
	size_t	max_row;
	size_t	index;

	max_row = p_row;
	index = p_row + 1;
	while (index < matrix->rows)
	{
		if (ft_abs(matrix->data[index][col]) > ft_abs(matrix->data[max_row][col]))
			max_row = index;
		index++;
	}
	return (max_row);
}

static int	gauss_step(t_matrix *m, size_t p_row, size_t col, int *sign, float *det)
{
	size_t	max_row;
	float	pivot;

	max_row = find_pivot(m, p_row, col);
	if (ft_abs(m->data[max_row][col]) < EPSILON)
		return (0);
	if (max_row != p_row)
	{
		swap_rows(m, p_row, max_row);
		*sign *= -1;
	}
	pivot = m->data[p_row][col];
	*det *= pivot;
	normalize_row(m, p_row, pivot);
	eliminate(m, p_row, col);
	return (1);
}

float	determinant(t_matrix *matrix)
{
	t_matrix	*result;
	float		det;
	int			sign;
	size_t		p_row;
	size_t		col;

	if (!mat_is_square(matrix))
		return (0);
	result = from_mat(matrix->data, matrix->rows, matrix->cols);
	if (!result)
		return (0);
	det = 1.0f;
	sign = 1;
	p_row = 0;
	col = 0;
	while (col < result->cols && p_row < result->rows)
	{
		if (!gauss_step(result, p_row, col, &sign, &det))
		{
			free_mat(result);
			return (0);
		}
		p_row++;
		col++;
	}
	free_mat(result);
	return (det * sign);
}

void	ex11(t_cli *cli)
{
	float	result;

	exercise_header(EX11_LABEL, EX11_NAME);
	if (cli->count < 1)
	{
		printf(RED "Erreur" RESET " : ex11 attend 1 matrice carrée\n");
		printf(GREY "Usage : ./matrix ex11 \"1,2;3,4\"\n" RESET);
		return ;
	}
	if (!mat_is_square(cli->mats[0]))
	{
		printf(RED "Erreur" RESET " : la matrice doit être carrée\n");
		return ;
	}
	result = determinant(cli->mats[0]);
	display_mat(cli->mats[0]);
	printf(GREY "det = " RESET "%g\n", result);
}
