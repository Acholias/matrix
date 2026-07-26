/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex07.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 13:36:32 by lumugot           #+#    #+#             */
/*   Updated: 2026/07/26 14:48:11 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exercises.h"

t_vector	*mul_vec(t_matrix *m, t_vector *v)
{
	t_vector	*result;
	size_t		i;
	size_t		j;

	result = new_vec(m->rows);
	if (!result)
		return (NULL);
	i = 0;
	while (i < m->rows)
	{
		j = 0;
		while (j < m->cols)
		{
			result->data[i] = fmaf(m->data[i][j], v->data[j], result->data[i]);
			j++;
		}
		i++;
	}
	return (result);
}

t_matrix	*mul_mat(t_matrix *m, t_matrix *n)
{
	t_matrix	*result;
	size_t		i;
	size_t		j;
	size_t		k;

	result = new_mat(m->rows, n->cols);
	if (!result)
		return (NULL);
	i = 0;
	while (i < m->rows)
	{
		j = 0;
		while (j < n->cols)
		{
			k = 0;
			while (k < m->cols)
			{
				result->data[i][j] = fmaf(m->data[i][k], n->data[k][j], result->data[i][j]);
				k++;
			}
			j++;
		}
		i++;
	}
	return (result);
}

void	ex07(void)
{
	printf("=== Exercise 07 - Linear Map, Matrix Multiplication ===\n\n");

	float row1[] = {1., 0.};
	float row2[] = {0., 1.};
	float *rows[] = {row1, row2};
	t_matrix *m = from_mat(rows, 2, 2);
	t_vector *v = from_vec((float[]){4., 2.}, 2);
	printf("Matrix * Vector:\n");
	print_mat(m);
	printf("*\n"); print_vec(v);
	printf("=\n");
	t_vector *res_v = mul_vec(m, v);
	print_vec(res_v);
	free_mat(m);
	free_vec(v);
	free_vec(res_v);

	float row3[] = {2., 0.};
	float row4[] = {0., 2.};
	float *rows2[] = {row3, row4};
	m = from_mat(rows2, 2, 2);
	v = from_vec((float[]){4., 2.}, 2);
	printf("\nMatrix * Vector:\n");
	print_mat(m);
	printf("*\n"); print_vec(v);
	printf("=\n");
	res_v = mul_vec(m, v);
	print_vec(res_v);
	free_mat(m);
	free_vec(v);
	free_vec(res_v);

	float row5[] = {2., -2.};
	float row6[] = {-2., 2.};
	float *rows3[] = {row5, row6};
	m = from_mat(rows3, 2, 2);
	v = from_vec((float[]){4., 2.}, 2);
	printf("\nMatrix * Vector:\n");
	print_mat(m);
	printf("*\n"); print_vec(v);
	printf("=\n");
	res_v = mul_vec(m, v);
	print_vec(res_v);
	free_mat(m);
	free_vec(v);
	free_vec(res_v);

    // Matrix * Matrix
	float ra1[] = {1., 0.};
	float ra2[] = {0., 1.};
	float *rowsA[] = {ra1, ra2};
	float rb1[] = {1., 0.};
	float rb2[] = {0., 1.};
	float *rowsB[] = {rb1, rb2};
	t_matrix *a = from_mat(rowsA, 2, 2);
	t_matrix *b = from_mat(rowsB, 2, 2);
	printf("\nMatrix * Matrix:\n");
	print_mat(a);
	printf("*\n"); print_mat(b);
	printf("=\n");
	t_matrix *res_m = mul_mat(a, b);
	print_mat(res_m);
	free_mat(a);
	free_mat(b);
	free_mat(res_m);

	float rc1[] = {1., 0.};
	float rc2[] = {0., 1.};
	float *rowsC[] = {rc1, rc2};
	float rd1[] = {2., 1.};
	float rd2[] = {4., 2.};
	float *rowsD[] = {rd1, rd2};
	a = from_mat(rowsC, 2, 2);
	b = from_mat(rowsD, 2, 2);
	printf("\nMatrix * Matrix:\n");
	print_mat(a);
	printf("*\n"); print_mat(b);
	printf("=\n");
	res_m = mul_mat(a, b);
	print_mat(res_m);
	free_mat(a);
	free_mat(b);
	free_mat(res_m);

	float re1[] = {3., -5.};
	float re2[] = {6., 8.};
	float *rowsE[] = {re1, re2};
	float rf1[] = {2., 1.};
	float rf2[] = {4., 2.};
	float *rowsF[] = {rf1, rf2};
	a = from_mat(rowsE, 2, 2);
	b = from_mat(rowsF, 2, 2);
	printf("\nMatrix * Matrix:\n");
	print_mat(a);
	printf("*\n"); print_mat(b);
	printf("=\n");
	res_m = mul_mat(a, b);
	print_mat(res_m);
	free_mat(a);
	free_mat(b);
free_mat(res_m);
}
