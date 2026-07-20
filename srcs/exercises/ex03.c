/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 14:39:53 by lumugot           #+#    #+#             */
/*   Updated: 2026/07/20 21:26:14 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exercises.h"

float	dot(t_vector *u, t_vector *v)
{
	float	result;
	size_t	index;

	result = 0;
	index = 0;
	while (index < u->size)
	{
		result = fmaf(u->data[index], v->data[index], result);
		index++;
	}
	return (result);
}

void	ex03()
{
	printf("=== Exercise 03 - Dot Product ===\n\n");

	t_vector *u = from_vec((float[]){0., 0.}, 2);
	t_vector *v = from_vec((float[]){1., 1.}, 2);
	printf("u = "); print_vec(u);
	printf("v = "); print_vec(v);
	printf("u · v = %g\n", dot(u, v));
	free_vec(u);
	free_vec(v);

	u = from_vec((float[]){1., 1.}, 2);
	v = from_vec((float[]){1., 1.}, 2);
	printf("\nu = "); print_vec(u);
	printf("v = "); print_vec(v);
	printf("u · v = %g\n", dot(u, v));
	free_vec(u);
	free_vec(v);

	u = from_vec((float[]){-1., 6.}, 2);
	v = from_vec((float[]){3., 2.}, 2);
	printf("\nu = "); print_vec(u);
	printf("v = "); print_vec(v);
	printf("u · v = %g\n", dot(u, v));
	free_vec(u);
	free_vec(v);
}
