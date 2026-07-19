/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 11:36:35 by lumugot           #+#    #+#             */
/*   Updated: 2026/07/19 11:59:37 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exercises.h"

void	vec_add(t_vector *u, const t_vector	*v)
{
	size_t	index;

	index = 0;
	while (index < u->size)
	{
		u->data[index] += v->data[index];
		index++;
	}
}

void	vec_sub(t_vector *u, const t_vector *v)
{
	size_t	index;

	index = 0;
	while (index < u->size)
	{
		u->data[index] -= v->data[index];
		index++;
	}
}

void	vec_scl(t_vector *u, float a)
{
	size_t	index;

	index = 0;
	while (index < u->size)
	{
		u->data[index] *= a;
		index++;
	}
}

void	mat_add(t_matrix *u, const t_matrix *v)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < u->rows)
	{
		j = 0;
		while (j < u->cols)
		{
			u->data[i][j] += v->data[i][j];
			j++;
		}

		i++;
	}
}

void	mat_sub(t_matrix *u, const t_matrix *v)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < u->rows)
	{

		j = 0;
		while (j < u->cols)
		{
			u->data[i][j] -= v->data[i][j];
			j++;
		}
		i++;
	}
}

void	mat_scl(t_matrix *u, float a)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < u->rows)
	{
		j = 0;
		while (j < u->cols)
		{
			u->data[i][j] *= a;
			j++;
		}
		i++;
	}
}

// TODO: Peut être des fonctions printeurs pour éviter ce genre de code horrible
void	ex00(void)
{
	printf("=== Exercise 00 - Add, Subtract and Scale ===\n\n");

	// Vector add
	t_vector *u = from_vec((float[]){2., 3.}, 2);
	t_vector *v = from_vec((float[]){5., 7.}, 2);
	printf("Vector add:\n");
	print_vec(u);
	printf("+\n");
	print_vec(v);
	printf("=\n");
	vec_add(u, v);
	print_vec(u);
	free_vec(u);
	free_vec(v);

	// Vector sub
	u = from_vec((float[]){2., 3.}, 2);
	v = from_vec((float[]){5., 7.}, 2);
	printf("\nVector sub:\n");
	print_vec(u);
	printf("-\n");
	print_vec(v);
	printf("=\n");
	vec_sub(u, v);
	print_vec(u);
	free_vec(u);
	free_vec(v);

	// Vector scl
	u = from_vec((float[]){2., 3.}, 2);
	printf("\nVector scl:\n");
	print_vec(u);
	printf("* 2\n=\n");
	vec_scl(u, 2.);
	print_vec(u);
	free_vec(u);

	// Matrix add
	float row_m1[] = {1., 2.};
	float row_m2[] = {3., 4.};
	float *rows_m[] = {row_m1, row_m2};

	float row_n1[] = {7., 4.};
	float row_n2[] = {-2., 2.};
	float *rows_n[] = {row_n1, row_n2};

	t_matrix *m = from_mat(rows_m, 2, 2);
	t_matrix *n = from_mat(rows_n, 2, 2);
	printf("\nMatrix add:\n");
	print_mat(m);
	printf("+\n");
	print_mat(n);
	printf("=\n");
	mat_add(m, n);
	print_mat(m);
	free_mat(m);
	free_mat(n);

	// Matrix sub
	m = from_mat(rows_m, 2, 2);
	n = from_mat(rows_n, 2, 2);
	printf("\nMatrix sub:\n");
	print_mat(m);
	printf("-\n");
	print_mat(n);
	printf("=\n");
	mat_sub(m, n);
	print_mat(m);
	free_mat(m);
	free_mat(n);

    // Matrix scl
	m = from_mat(rows_m, 2, 2);
	printf("\nMatrix scl:\n");
	print_mat(m);
	printf("* 2\n=\n");
	mat_scl(m, 2.);
	print_mat(m);
	free_mat(m);
}
