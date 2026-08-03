/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex08.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 14:51:11 by lumugot           #+#    #+#             */
/*   Updated: 2026/08/03 10:55:51 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exercises.h"

float	trace(t_matrix *matrix)
{
	float	result;
	size_t	index;

	result = 0;
	index = 0;
	while (index < matrix->rows)
	{
		result += matrix->data[index][index];
		index++;
	}
	return (result);
}

void	ex08(t_cli *cli)
{
	t_matrix	*m;
	float		result;

	exercise_header(EX08_LABEL, EX08_NAME);
	if (cli->count < 1)
	{
		printf(RED "Erreur" RESET " : ex08 attend 1 matrice carrée\n");
		printf(GREY "Usage : ./matrix ex08 \"1,2;3,4\"\n" RESET);
		return ;
	}
	m = cli->mats[0];
	if (!mat_is_square(m))
	{
		printf(RED "Erreur" RESET " : la matrice doit être carrée\n");
		return ;
	}
	result = trace(m);
	display_mat(m);
	printf(GREY "trace = " RESET "%g\n", result);
}
