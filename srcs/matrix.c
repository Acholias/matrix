/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 10:48:42 by lumugot           #+#    #+#             */
/*   Updated: 2026/07/19 11:06:51 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static float	**allocs_rows(size_t rows, size_t cols)
{
	float	**data;
	size_t	index;

	data = malloc(sizeof(float *) * rows);
	if (!data)
		return (NULL);
	index = 0;
	while (index < rows)
	{
		data[index] = malloc(sizeof(float) * cols);
		if (!data[index])
		{
			while (index--)
				free(data[index]);
			free(data);
			return (NULL);
		}
		memset(data[index], 0, sizeof(float) * cols);
		index++;
	}
	return (data);
}

t_matrix	*new_mat(size_t	rows, size_t cols)
{
	t_matrix	*matrix;

	matrix = malloc(sizeof(t_matrix));
	if (!matrix)
		return (NULL);
	matrix->data = allocs_rows(rows, cols);
	if (!matrix->data)
	{
		free(matrix);
		return (NULL);
	}
	matrix->rows = rows;
	matrix->cols = cols;
	return (matrix);
}

t_matrix	*from_mat(float **data, size_t rows, size_t cols)
{
	t_matrix	*matrix;
	size_t		index;

	matrix = new_mat(rows, cols);
	if (!matrix)
		return (NULL);
	index = 0;
	while (index < rows)
	{
		memcpy(matrix->data[index], data[index], sizeof(float) * cols);
		index++;
	}
	return (matrix);
}

void	free_mat(t_matrix *matrix)
{
	size_t	index;

	if (!matrix)
		return ;
	index = 0;
	while (index < matrix->rows)
	{
		free(matrix->data[index]);
		index++;
	}
	free(matrix->data);
	free(matrix);
}

void	print_mat(const t_matrix *matrix)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < matrix->rows)
	{
		printf("[");
		j = 0;
		while (j < matrix->cols)
		{
			printf("%g", matrix->data[i][j]);
			if (j < matrix->cols - 1)
				printf(", ");
			j++;
		}
		printf("]\n");
		i++;
	}
}

bool	mat_is_square(const t_matrix *matrix)
{
	return (matrix->rows == matrix->cols);
}
