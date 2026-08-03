/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex09.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 14:59:52 by lumugot           #+#    #+#             */
/*   Updated: 2026/08/03 11:01:05 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exercises.h"

t_matrix	*transpose(t_matrix *matrix)
{
	t_matrix	*result;
	size_t		i;
	size_t		j;

	result = new_mat(matrix->cols, matrix->rows);
	if (!result)
		return (NULL);
	
	i = 0;
	while (i < matrix->rows)
	{
		j = 0;
		while (j < matrix->cols)
		{
			result->data[j][i] = matrix->data[i][j];
			j++;
		}
		i++;
	}
	return (result);
}

void	ex09(t_cli *cli)
{
	t_matrix	*result;

	exercise_header(EX09_LABEL, EX09_NAME);
	if (cli->count < 1)
	{
		printf(RED "Erreur" RESET " : ex09 attend 1 matrice\n");
		printf(GREY "Usage : ./matrix ex09 \"1,2,3;4,5,6\"\n" RESET);
		return ;
	}
	result = transpose(cli->mats[0]);
	display_mat(cli->mats[0]);
	printf(GREY "^T =\n" RESET);
	display_mat(result);
	free_mat(result);
}
