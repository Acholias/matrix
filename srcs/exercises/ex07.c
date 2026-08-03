/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex07.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 13:36:32 by lumugot           #+#    #+#             */
/*   Updated: 2026/08/03 10:55:58 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exercises.h"

t_vector	*mul_vec(t_matrix *m, t_vector *v)
{
	t_vector	*result;
	size_t		i;
	size_t		j;

	result = new_vec(m->rows);
	if (!result)
		return (NULL);
	i = 0;
	while (i < m->rows)
	{
		j = 0;
		while (j < m->cols)
		{
			result->data[i] = fmaf(m->data[i][j], v->data[j], result->data[i]);
			j++;
		}
		i++;
	}
	return (result);
}

t_matrix	*mul_mat(t_matrix *m, t_matrix *n)
{
	t_matrix	*result;
	size_t		i;
	size_t		j;
	size_t		k;

	result = new_mat(m->rows, n->cols);
	if (!result)
		return (NULL);
	i = 0;
	while (i < m->rows)
	{
		j = 0;
		while (j < n->cols)
		{
			k = 0;
			while (k < m->cols)
			{
				result->data[i][j] = fmaf(m->data[i][k], n->data[k][j], result->data[i][j]);
				k++;
			}
			j++;
		}
		i++;
	}
	return (result);
}

void	ex07(t_cli *cli)
{
	t_matrix	*result;

	exercise_header(EX07_LABEL, EX07_NAME);
	if (cli->count < 2)
	{
		printf(RED "Erreur" RESET " : ex07 attend 2 matrices\n");
		printf(GREY "Usage : ./matrix ex07 \"1,0;0,1\" \"2,1;4,2\"\n" RESET);
		return ;
	}
	if (cli->mats[0]->cols != cli->mats[1]->rows)
	{
		printf(RED "Erreur" RESET " : colonnes de A doivent égaler lignes de B\n");
		return ;
	}
	result = mul_mat(cli->mats[0], cli->mats[1]);
	display_mat_result("×", cli->mats[0], cli->mats[1], result);
	free_mat(result);
}
