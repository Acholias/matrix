/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex09.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 14:59:52 by lumugot           #+#    #+#             */
/*   Updated: 2026/07/26 15:19:12 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exercises.h"

t_matrix	*transpose(t_matrix *matrix)
{
	t_matrix	*result;
	size_t		i;
	size_t		j;

	result = new_mat(matrix->cols, matrix->rows);
	if (!result)
		return (NULL);
	
	i = 0;
	while (i < matrix->rows)
	{
		j = 0;
		while (j < matrix->cols)
		{
			result->data[j][i] = matrix->data[i][j];
			j++;
		}
		i++;
	}
	return (result);
}

void	ex09(void)
{
	printf("=== Exercise 09 - Transpose ===\n\n");

	float r1[] = {1., 2.};
	float r2[] = {3., 4.};
	float *rows1[] = {r1, r2};
	t_matrix *m = from_mat(rows1, 2, 2);
	printf("Matrix:\n"); print_mat(m);
	printf("transpose =\n");
	t_matrix *result = transpose(m);
	print_mat(result);
	free_mat(m);
	free_mat(result);

	float r3[] = {1., 2., 3.};
	float r4[] = {4., 5., 6.};
	float *rows2[] = {r3, r4};
	m = from_mat(rows2, 2, 3);
	printf("\nMatrix:\n"); print_mat(m);
	printf("transpose =\n");
	result = transpose(m);
	print_mat(result);
	free_mat(m);
	free_mat(result);

	float r5[] = {1., 2., 3.};
	float r6[] = {4., 5., 6.};
	float r7[] = {7., 8., 9.};
	float *rows3[] = {r5, r6, r7};
	m = from_mat(rows3, 3, 3);
	printf("\nMatrix:\n"); print_mat(m);
	printf("transpose =\n");
	result = transpose(m);
	print_mat(result);
	free_mat(m);
	free_mat(result);
}
