/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 19:16:11 by lumugot           #+#    #+#             */
/*   Updated: 2026/08/05 12:16:50 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exercises.h"

float	norm_1(t_vector *vector)
{
	float	result;
	size_t	index;

	result = 0;
	index = 0;
	while (index < vector->size)
	{
		result += ft_abs(vector->data[index]);
		index++;
	}
	return (result);
}

float	norm(t_vector *vector)
{
	float	result;
	size_t	index;

	result = 0;
	index = 0;
	while (index < vector->size)
	{
		result = fmaf(vector->data[index], vector->data[index], result);
		index++;
	}
	return (ft_sqrt(result));
}

float	norm_inf(t_vector *vector)
{
	float	result;
	float	f_abs;
	size_t	index;

	result = 0;
	index = 0;
	while (index < vector->size)
	{
		f_abs = ft_abs(vector->data[index]);
		if (f_abs > result)
			result = f_abs;
		index++;
	}
	return (result);
}

void	ex04(t_cli *cli)
{
	t_vector	*u;

	exercise_header(EX04_LABEL, EX04_NAME);
	if (cli->count < 1)
	{
		printf(RED "Erreur" RESET " : ex04 attend 1 vecteur\n");
		printf(GREY "Usage : ./matrix ex04 \"1,2,3\"\n" RESET);
		return ;
	}
	u = mat_to_vec(cli->mats[0]);
	display_vec_label(GREY "u        " RESET, u);
	printf(GREY "norm_1   " RESET "= %g\n", norm_1(u));
	printf(GREY "norm     " RESET "= %g\n", norm(u));
	printf(GREY "norm_inf " RESET "= %g\n", norm_inf(u));
	free_vec(u);
}
