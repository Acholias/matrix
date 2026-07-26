/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 19:16:11 by lumugot           #+#    #+#             */
/*   Updated: 2026/07/26 13:07:33 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exercises.h"

float	norm_1(t_vector *vector)
{
	float	result;
	size_t	index;

	result = 0;
	index = 0;
	while (index < vector->size)
	{
		result += fabsf(vector->data[index]);
		index++;
	}
	return (result);
}

float	norm(t_vector *vector)
{
	float	result;
	size_t	index;

	result = 0;
	index = 0;
	while (index < vector->size)
	{
		result = fmaf(vector->data[index], vector->data[index], result);
		index++;
	}
	return (sqrt(result));
}

float	norm_inf(t_vector *vector)
{
	float	result;
	float	f_abs;
	size_t	index;

	result = 0;
	index = 0;
	while (index < vector->size)
	{
		f_abs = fabsf(vector->data[index]);
		if (f_abs > result)
			result = f_abs;
		index++;
	}
	return (result);
}

void	ex04(void)
{
	printf("=== Exercise 04 - Norm ===\n\n");

	t_vector *u = from_vec((float[]){0., 0., 0.}, 3);
	printf("u = "); print_vec(u);
	printf("norm_1   = %g\n", norm_1(u));
	printf("norm     = %g\n", norm(u));
	printf("norm_inf = %g\n", norm_inf(u));
	free_vec(u);

	u = from_vec((float[]){1., 2., 3.}, 3);
	printf("\nu = "); print_vec(u);
	printf("norm_1   = %g\n", norm_1(u));
	printf("norm     = %g\n", norm(u));
	printf("norm_inf = %g\n", norm_inf(u));
	free_vec(u);

	u = from_vec((float[]){-1., -2.}, 2);
	printf("\nu = "); print_vec(u);
	printf("norm_1   = %g\n", norm_1(u));
	printf("norm     = %g\n", norm(u));
	printf("norm_inf = %g\n", norm_inf(u));
	free_vec(u);
}
