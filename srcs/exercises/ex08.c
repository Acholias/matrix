/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex08.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 14:51:11 by lumugot           #+#    #+#             */
/*   Updated: 2026/07/26 14:57:45 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exercises.h"

float	trace(t_matrix *matrix)
{
	float	result;
	size_t	index;

	result = 0;
	index = 0;
	while (index < matrix->rows)
	{
		result += matrix->data[index][index];
		index++;
	}
	return (result);
}

void	ex08(void)
{
	printf("=== Exercise 08 - Trace ===\n\n");

	float r1[] = {1., 0.};
	float r2[] = {0., 1.};
	float *rows1[] = {r1, r2};
	t_matrix *m = from_mat(rows1, 2, 2);
	printf("Matrix:\n"); print_mat(m);
	printf("trace = %g\n", trace(m));
	free_mat(m);

	float r3[] = {2., -5., 0.};
	float r4[] = {4.,  3., 7.};
	float r5[] = {-2., 3., 4.};
	float *rows2[] = {r3, r4, r5};
	m = from_mat(rows2, 3, 3);
	printf("\nMatrix:\n"); print_mat(m);
	printf("trace = %g\n", trace(m));
	free_mat(m);

	float r6[] = {-2., -8.,  4.};
	float r7[] = { 1., -23., 4.};
	float r8[] = { 0.,   6., 4.};
	float *rows3[] = {r6, r7, r8};
	m = from_mat(rows3, 3, 3);
	printf("\nMatrix:\n"); print_mat(m);
	printf("trace = %g\n", trace(m));
	free_mat(m);
}
