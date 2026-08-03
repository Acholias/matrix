/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex05.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 19:30:23 by lumugot           #+#    #+#             */
/*   Updated: 2026/08/03 10:56:08 by lumugot          ###   ########.fr       */
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

void	ex05(t_cli *cli)
{
	t_vector	*u;
	t_vector	*v;
	float		result;

	exercise_header(EX05_LABEL, EX05_NAME);
	if (cli->count < 2)
	{
		printf(RED "Erreur" RESET " : ex05 attend 2 vecteurs\n");
		printf(GREY "Usage : ./matrix ex05 \"1,0\" \"0,1\"\n" RESET);
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
	result = angle_cos(u, v);
	display_scalar_result("cos", u, v, result);
	free_vec(u);
	free_vec(v);
}
