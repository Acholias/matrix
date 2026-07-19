/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 10:37:26 by lumugot           #+#    #+#             */
/*   Updated: 2026/07/19 11:50:55 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

t_vector	*new_vec(size_t size)
{
	t_vector	*vector;

	vector = malloc(sizeof(t_vector));
	if (!vector)
		return (NULL);
	vector->data = malloc(sizeof(float) * size);
	if (!vector->data)
	{
		free(vector);
		return (NULL);
	}
	memset(vector->data, 0, sizeof(float) * size);
	vector->size = size;
	return (vector);
}

t_vector	*from_vec(float *data, size_t size)
{
	t_vector	*vector;

	vector = new_vec(size);
	if (!vector)
		return (NULL);
	memcpy(vector->data, data, size * sizeof(float));
	return (vector);
}

void	free_vec(t_vector *vector)
{
	if (!vector)
		return ;
	free(vector->data);
	free(vector);
}

void	print_vec(const t_vector *vector)
{
	size_t	index;

	index = 0;
	while (index < vector->size)
	{
		printf("[%g]\n", vector->data[index]);
		index++;
	}
}
