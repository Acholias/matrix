/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex12.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 11:28:35 by lumugot           #+#    #+#             */
/*   Updated: 2026/08/05 12:17:37 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exercises.h"

static t_matrix	*augmented_matrix(t_matrix *matrix)
{
	t_matrix	*augmented;
	size_t		i;
	size_t		j;

	augmented = new_mat(matrix->rows, matrix->cols * 2);
	if (!augmented)
		return (NULL);
	i = 0;
	while (i < matrix->rows)
	{
		j = 0;
		while (j < matrix->cols)
		{
			augmented->data[i][j] = matrix->data[i][j];
			augmented->data[i][j + matrix->cols] = (i == j) ? 1.0f : 0.0f;
			j++;
		}
		i++;
	}
	return (augmented);
}

static t_matrix	*extract_inverse(t_matrix *augmented, size_t n)
{
	t_matrix	*inversed;
	size_t		i;
	size_t		j;

	inversed = new_mat(n, n);
	if (!inversed)
		return (NULL);
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			inversed->data[i][j] = augmented->data[i][j + n];
			j++;
		}
		i++;
	}
	return (inversed);
}

t_matrix	*inverse(t_matrix *matrix)
{
	t_matrix	*augmented;
	t_matrix	*inversed;
	size_t		p_row;
	size_t		col;
	size_t		max_row;
	float		pivot;

	if (!mat_is_square(matrix))
		return (NULL);
	if (ft_abs(determinant(matrix)) < EPSILON)
		return (NULL);
	augmented = augmented_matrix(matrix);
	if (!augmented)
		return (NULL);
	p_row = 0;
	col = 0;
	while (col < matrix->cols && p_row < matrix->rows)
	{
		max_row = find_pivot(augmented, p_row, col);
		if (ft_abs(augmented->data[max_row][col]) < EPSILON)
		{
			col++;
			continue ;
		}
		if (max_row != p_row)
			swap_rows(augmented, p_row, max_row);
		pivot = augmented->data[p_row][col];
		normalize_row(augmented, p_row, pivot);
		eliminate(augmented, p_row, col);
		p_row++;
		col++;
	}
	inversed = extract_inverse(augmented, matrix->rows);
	free_mat(augmented);
	return (inversed);
}

void	ex12(t_cli *cli)
{
	t_matrix	*result;

	exercise_header(EX12_LABEL, EX12_NAME);
	if (cli->count < 1)
	{
		printf(RED "Erreur" RESET " : ex12 attend 1 matrice carrée\n");
		printf(GREY "Usage : ./matrix ex12 \"1,2;3,4\"\n" RESET);
		return ;
	}
	if (!mat_is_square(cli->mats[0]))
	{
		printf(RED "Erreur" RESET " : la matrice doit être carrée\n");
		return ;
	}
	result = inverse(cli->mats[0]);
	if (!result)
	{
		printf(RED "Erreur" RESET " : la matrice n'est pas inversible (det = 0)\n");
		return ;
	}
	display_mat(cli->mats[0]);
	printf(GREY "inverse =\n" RESET);
	display_mat(result);
	free_mat(result);
}
