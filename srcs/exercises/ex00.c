/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 11:36:35 by lumugot           #+#    #+#             */
/*   Updated: 2026/08/02 23:42:21 by lumugot          ###   ########.fr       */
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

void	ex00(t_cli *cli)
{
	t_matrix    *u;
	t_matrix    *v;
	t_matrix    *result;
	exercise_header(EX00_LABEL, EX00_NAME);

	u = cli->mats[0];
	v = cli->mats[1];
	if (u->rows != v->rows || u->cols != v->cols)
	{
		printf(RED "Erreur" RESET " : les matrices doivent être de la même taille\n");
		return ;
	}
	result = from_mat(u->data, u->rows, u->cols);
	mat_add(result, v);
	display_mat_result("+", u, v, result);
	free_mat(result);

	printf("\n");

	result = from_mat(u->data, u->rows, u->cols);
	mat_sub(result, v);
	display_mat_result("-", u, v, result);
	free_mat(result);
}
