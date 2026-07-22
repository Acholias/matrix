/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 13:46:36 by lumugot           #+#    #+#             */
/*   Updated: 2026/07/22 19:39:22 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exercises.h"

float	lerp_float(float u, float v, float t)
{
	return (fmaf(t, v - u, u));
}

t_vector	*lerp_vec(t_vector *u, t_vector *v, float t)
{
	t_vector	*result;
	size_t		index;

	result = new_vec(u->size);
	if (!result)
		return (NULL);
	index = 0;
	while (index < u->size)
	{
		result->data[index] = lerp_float(u->data[index], v->data[index], t);
		index++;
	}
	return (result);
}

t_matrix	*lerp_mat(t_matrix *u, t_matrix *v, float t)
{
	t_matrix	*result;
	size_t		i;
	size_t		j;

	result = new_mat(u->rows, u->cols);
	if (!result)
		return (NULL);
	i = 0;
	while (i < u->rows)
	{
		j = 0;
		while (j < u->cols)
		{
			result->data[i][j] = lerp_float(u->data[i][j], v->data[i][j], t);
			j++;
		}
		i++;
	}
	return (result);
}

void	ex02()
{
	printf("=== Exercise 02 - Linear Interpolation ===\n\n");

	printf("lerp(0, 1, 0)   = %g\n",    lerp_float(0., 1., 0.));
	printf("lerp(0, 1, 1)   = %g\n",    lerp_float(0., 1., 1.));
	printf("lerp(0, 1, 0.5) = %g\n",    lerp_float(0., 1., 0.5));
	printf("lerp(21, 42, 0.3) = %g\n",  lerp_float(21., 42., 0.3));

	t_vector *u = from_vec((float[]){2., 1.}, 2);
	t_vector *v = from_vec((float[]){4., 2.}, 2);
	printf("\nlerp(v=[2,1], v=[4,2], t=0.3):\n");
	printf("u = "); print_vec(u);
	printf("v = "); print_vec(v);
	printf("t = 0.3\n=\n");
	t_vector *res_vec = lerp_vec(u, v, 0.3);
	print_vec(res_vec);
	free_vec(u);
	free_vec(v);
	free_vec(res_vec);

	float row_u1[] = {2., 1.};
	float row_u2[] = {3., 4.};
	float *rows_u[] = {row_u1, row_u2};

	float row_v1[] = {20., 10.};
	float row_v2[] = {30., 40.};
	float *rows_v[] = {row_v1, row_v2};

	t_matrix *mu = from_mat(rows_u, 2, 2);
	t_matrix *mv = from_mat(rows_v, 2, 2);
	printf("\nlerp(mat, mat, t=0.5):\n");
	print_mat(mu);
	printf("t = 0.5\n=\n");
	t_matrix *res_mat = lerp_mat(mu, mv, 0.5);
	print_mat(res_mat);
	free_mat(mu);
	free_mat(mv);
	free_mat(res_mat);
}
