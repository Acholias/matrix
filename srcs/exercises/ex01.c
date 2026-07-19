/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 13:33:09 by lumugot           #+#    #+#             */
/*   Updated: 2026/07/19 13:33:39 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exercises.h"

t_vector	*linear_combination(t_vector **u, float *coefs, size_t len)
{
	t_vector	*result;
	size_t		i;
	size_t		j;

	result = new_vec(len);
	if (!result)
		return (NULL);
	j = 0;
	while (j < len)
	{
		i = 0;
		while (i < result->size)
		{
			result->data[i] = fmaf(coefs[j], u[j]->data[i], result->data[i]);
			i++;
		}
		j++;
	}
	return (result);
}

void	ex01(void)
{
	printf("=== Exercise 01 - Linear Combination ===\n\n");

	// e1, e2, e3 avec coefs 10, -2, 0.5
	t_vector *e1 = from_vec((float[]){1., 0., 0.}, 3);
	t_vector *e2 = from_vec((float[]){0., 1., 0.}, 3);
	t_vector *e3 = from_vec((float[]){0., 0., 1.}, 3);
	t_vector *vecs1[] = {e1, e2, e3};
	float coefs1[] = {10., -2., 0.5};

	printf("linear_combination([e1, e2, e3], [10, -2, 0.5]):\n");
	printf("e1 = "); print_vec(e1);
	printf("e2 = "); print_vec(e2);
	printf("e3 = "); print_vec(e3);
	printf("coefs = [10, -2, 0.5]\n");
	printf("=\n");
	t_vector *result = linear_combination(vecs1, coefs1, 3);
	print_vec(result);
	free_vec(result);
	free_vec(e1);
	free_vec(e2);
	free_vec(e3);

	// v1, v2 avec coefs 10, -2
	t_vector *v1 = from_vec((float[]){1., 2., 3.}, 3);
	t_vector *v2 = from_vec((float[]){0., 10., -100.}, 3);
	t_vector *vecs2[] = {v1, v2};

	float coefs2[] = {10., -2.};

	printf("\nlinear_combination([v1, v2], [10, -2]):\n");
	printf("v1 = "); print_vec(v1);
	printf("v2 = "); print_vec(v2);
	printf("coefs = [10, -2]\n");
	printf("=\n");
	result = linear_combination(vecs2, coefs2, 2);
	print_vec(result);
	free_vec(result);
	free_vec(v1);
	free_vec(v2);
}
