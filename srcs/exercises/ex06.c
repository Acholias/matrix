/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex06.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 19:44:57 by lumugot           #+#    #+#             */
/*   Updated: 2026/07/26 13:22:48 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exercises.h"

t_vector	*cross_product(t_vector *u, t_vector *v)
{
	t_vector	*result;

	result = new_vec(3);
	if (!result)
		return (NULL);
	result->data[0] = u->data[1] * v->data[2] - u->data[2] * v->data[1];
	result->data[1] = u->data[2] * v->data[0] - u->data[0] * v->data[2];
	result->data[2] = u->data[0] * v->data[1] - u->data[1] * v->data[0];
	return (result);
}

void	ex06(void)
{
	printf("=== Exercise 06 - Cross Product ===\n\n");

	t_vector *u = from_vec((float[]){0., 0., 1.}, 3);
	t_vector *v = from_vec((float[]){1., 0., 0.}, 3);
	printf("u = "); print_vec(u);
	printf("v = "); print_vec(v);
	printf("u × v =\n");
	t_vector *result = cross_product(u, v);
	print_vec(result);
	free_vec(u);
	free_vec(v);
	free_vec(result);

    u = from_vec((float[]){1., 2., 3.}, 3);
	v = from_vec((float[]){4., 5., 6.}, 3);
	printf("\nu = "); print_vec(u);
	printf("v = "); print_vec(v);
	printf("u × v =\n");
	result = cross_product(u, v);
	print_vec(result);
	free_vec(u);
	free_vec(v);
	free_vec(result);

	u = from_vec((float[]){4., 2., -3.}, 3);
	v = from_vec((float[]){-2., -5., 16.}, 3);
	printf("\nu = "); print_vec(u);
	printf("v = "); print_vec(v);
	printf("u × v =\n");
	result = cross_product(u, v);
	print_vec(result);
	free_vec(u);
	free_vec(v);
	free_vec(result);
}
