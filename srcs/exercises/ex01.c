/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 13:33:09 by lumugot           #+#    #+#             */
/*   Updated: 2026/08/03 11:18:50 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exercises.h"

t_vector	*linear_combination(t_vector **u, float *coefs, size_t len)
{
	t_vector	*result;
	size_t		i;
	size_t		j;

	result = new_vec(u[0]->size);
	if (!result)
		return (NULL);
	j = 0;
	while (j < len)
	{
		i = 0;
		while (i < result->size)
		{
			result->data[i] = fmaf(coefs[j], u[j]->data[i], result->data[i]);
			i++;
		}
		j++;
	}
	return (result);
}

void	ex01(t_cli *cli)
{
	t_vector	**vecs;
	t_vector	*result;
	char		buf[16];
	size_t		index;

	exercise_header(EX01_LABEL, EX01_NAME);
	if (cli->count < 1)
	{
		printf(RED "Erreur" RESET " : ex01 attend au moins 2 vecteurs\n");
		printf(GREY "Usage : ./matrix ex01 \"1,0,0\" \"0,1,0\" -s 10,-2\n" RESET);
		return ;
	}
	if (!cli->has_scalar || cli->count_scalar != cli->count)
	{
		printf(RED "Erreur" RESET " : ex01 attend autant de scalaires que de vecteurs\n");
		printf(GREY "Usage : ./matrix ex01 \"1,0,0\" \"0,1,0\" -s 10,-2\n" RESET);
		return ;
	}
	vecs = malloc(sizeof(t_vector *) * cli->count);
	if (!vecs)
		return ;
	index = 0;
	while (index < cli->count)
	{
		vecs[index] = mat_to_vec(cli->mats[index]);
		if (!vecs[index])
		{
			while (index > 0)
			{
				index--;
				free_vec(vecs[index]);
			}
			free(vecs);
			return ;
		}
		index++;
	}
	result = linear_combination(vecs, cli->scalars, cli->count);
	index = 0;
	while (index < cli->count)
	{
		snprintf(buf, sizeof(buf), GREY "v%zu  " RESET, index + 1);
		display_vec_label(buf, vecs[index]);
		printf(GREY "* %g\n" RESET, cli->scalars[index]);
		if (index < cli->count - 1)
			printf("\n");
		index++;
	}
	printf(GREY "=\n" RESET);
	display_vec(result);
	index = 0;
	while (index < cli->count)
	{
		free_vec(vecs[index]);
		index++;
	}
	free(vecs);
	free_vec(result);
}
