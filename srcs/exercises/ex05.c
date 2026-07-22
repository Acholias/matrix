/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex05.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 19:30:23 by lumugot           #+#    #+#             */
/*   Updated: 2026/07/22 19:55:01 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exercises.h"

float	angle_cos(t_vector *u, t_vector *v)
{
	float	r_dot;
	float	norm_u;
	float	norm_v;

	r_dot = dot(u, v);
	norm_u = norm(u);
	norm_v = norm(v);
	return (r_dot / (norm_u * norm_v));
}

void	ex05(void)
{
	printf("=== Exercise 05 - Cos ===\n\n");
	t_vector *u = from_vec((float[]){1., 0.}, 2);
	t_vector *v = from_vec((float[]){1., 0.}, 2);
	printf("u = "); print_vec(u);
	printf("v = "); print_vec(v);
	printf("cos = %g\n", angle_cos(u, v));
	free_vec(u);
	free_vec(v);

	u = from_vec((float[]){1., 0.}, 2);
	v = from_vec((float[]){0., 1.}, 2);
	printf("\nu = "); print_vec(u);
	printf("v = "); print_vec(v);
	printf("cos = %g\n", angle_cos(u, v));
	free_vec(u);
	free_vec(v);

	u = from_vec((float[]){-1., 1.}, 2);
	v = from_vec((float[]){1., -1.}, 2);
	printf("\nu = "); print_vec(u);
	printf("v = "); print_vec(v);
	printf("cos = %g\n", angle_cos(u, v));
	free_vec(u);
	free_vec(v);

	u = from_vec((float[]){2., 1.}, 2);
	v = from_vec((float[]){4., 2.}, 2);
	printf("\nu = "); print_vec(u);
	printf("v = "); print_vec(v);
	printf("cos = %g\n", angle_cos(u, v));
	free_vec(u);
	free_vec(v);

	u = from_vec((float[]){1., 2., 3.}, 3);
	v = from_vec((float[]){4., 5., 6.}, 3);
	printf("\nu = "); print_vec(u);
	printf("v = "); print_vec(v);
	printf("cos = %g\n", angle_cos(u, v));
	free_vec(u);
	free_vec(v);
}

