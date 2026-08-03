/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex06.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 19:44:57 by lumugot           #+#    #+#             */
/*   Updated: 2026/08/03 10:56:04 by lumugot          ###   ########.fr       */
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

void	ex06(t_cli *cli)
{
	t_vector	*u;
	t_vector	*v;
	t_vector	*result;

	exercise_header(EX06_LABEL, EX06_NAME);
	if (cli->count < 2)
	{
		printf(RED "Erreur" RESET " : ex06 attend 2 vecteurs 3D\n");
		printf(GREY "Usage : ./matrix ex06 \"1,0,0\" \"0,1,0\"\n" RESET);
		return ;
	}
	u = mat_to_vec(cli->mats[0]);
	v = mat_to_vec(cli->mats[1]);
	if (u->size != 3 || v->size != 3)
	{
		printf(RED "Erreur" RESET " : ex06 attend des vecteurs 3D\n");
		free_vec(u);
		free_vec(v);
		return ;
	}
	result = cross_product(u, v);
	display_vec_result("×", u, v, result);
	free_vec(u);
	free_vec(v);
	free_vec(result);
}
