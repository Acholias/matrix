/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 14:39:53 by lumugot           #+#    #+#             */
/*   Updated: 2026/08/03 10:56:16 by lumugot          ###   ########.fr       */
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

void	ex03(t_cli *cli)
{
	t_vector	*u;
	t_vector	*v;
	float		result;

	exercise_header(EX03_LABEL, EX03_NAME);
	if (cli->count < 2)
	{
		printf(RED "Erreur" RESET " : ex03 attend 2 vecteurs\n");
		printf(GREY "Usage : ./matrix ex03 \"1,2,3\" \"4,5,6\"\n" RESET);
		return ;
	}
	u = mat_to_vec(cli->mats[0]);
	v = mat_to_vec(cli->mats[1]);
	if (u->size != v->size)
	{
		printf(RED "Erreur" RESET " : les vecteurs doivent être de la même taille\n");
		free_vec(u);
		free_vec(v);
		return ;
	}
	result = dot(u, v);
	display_scalar_result("·", u, v, result);
	free_vec(u);
	free_vec(v);
}
