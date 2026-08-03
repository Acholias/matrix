/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 13:46:36 by lumugot           #+#    #+#             */
/*   Updated: 2026/08/03 11:06:15 by lumugot          ###   ########.fr       */
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

void	ex02(t_cli *cli)
{
	t_vector	*u;
	t_vector	*v;
	t_vector	*result;
	float		t;

	exercise_header(EX02_LABEL, EX02_NAME);
	if (cli->count < 2)
	{
		printf(RED "Erreur" RESET " : ex02 attend 2 vecteurs\n");
		printf(GREY "Usage : ./matrix ex02 \"1,2\" \"4,2\" -s 0.3\n" RESET);
		return ;
	}
	if (!cli->has_scalar)
	{
		printf(RED "Erreur" RESET " : ex02 attend un scalaire t entre 0 et 1\n");
		printf(GREY "Usage : ./matrix ex02 \"1,2\" \"4,2\" -s 0.3\n" RESET);
		return ;
	}
	t = cli->scalars[0];
	if (t < 0 || t > 1)
	{
		printf(RED "Erreur" RESET " : t doit être entre 0 et 1\n");
		return ;
	}
	u = mat_to_vec(cli->mats[0]);
	v = mat_to_vec(cli->mats[1]);
	result = lerp_vec(u, v, t);
	display_vec_label(GREY "u  " RESET, u);
	display_vec_label(GREY "v  " RESET, v);
	printf(GREY "t = %g\n=\n" RESET, t);
	display_vec(result);
	free_vec(u);
	free_vec(v);
	free_vec(result);
}
