/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 20:09:34 by lumugot           #+#    #+#             */
/*   Updated: 2026/07/26 20:49:10 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/display.h"

static int	float_width(float value)
{
	char	buffer[64];

	snprintf(buffer, sizeof(buffer), "%g", value);
	return ((int)strlen(buffer));
}

static int	*col_widths(t_matrix *matrix)
{
	int		*res;
	size_t	i;
	size_t	j;
	int		f_res;

	res = malloc(sizeof(int) * matrix->cols);
	if (!res)
		return (NULL);
	j = 0;
	while (j < matrix->cols)
	{
		res[j] = 0;
		i = 0;
		while (i < matrix->rows)
		{
			f_res = float_width(matrix->data[i][j]);
			if (f_res > res[j])
				res[j] = f_res;
			i++;
		}
		j++;
	}
	return (res);
}

static const char	*open_brace(size_t row, size_t total)
{
	if (total == 1 || row == 0)
		return ("⎡");
	if (row == total - 1)
		return ("⎣");
	else
		return ("⎢");
}

static const char	*close_brace(size_t row, size_t total)
{
	if (total == 1 || row == 0)
		return ("⎤");
	if (row == total - 1)
		return ("⎦");
	else
		return ("⎥");
}

static t_matrix	*vec_to_mat(t_vector *vector)
{
	t_matrix	*matrix;
	size_t		index;

	matrix = new_mat(vector->size, 1);
	if (!matrix)
		return (NULL);
	index = 0;
	while (index < vector->size)
	{
		matrix->data[index][0] = vector->data[index];
		index++;
	}
	return (matrix);
}

static void	print_row(t_matrix *matrix, size_t row, int *w)
{
	size_t	index;

	printf("%s", open_brace(row, matrix->rows));

	index = 0;
	while (index < matrix->rows)
	{
		printf(" %*g", w[index], matrix->data[row][index]);
		index++;
	}
	printf(" %s", close_brace(row, matrix->rows));
}

static void	print_sep(char *sep, size_t row, size_t mid)
{
	if (row == mid)
		printf("  %s  ", sep);
	else
		printf("%*s", (int)(strlen(sep) + 4), "");
}

void	display_vec(t_vector *vector)
{
	t_matrix	*matrix;

	matrix = vec_to_mat(vector);
	if (!matrix)
		return ;
	display_mat(matrix);
	free_mat(matrix);
}

void	display_mat(t_matrix *matrix)
{
	int		*w;
	size_t	index;

	w = col_widths(matrix);
	if (!w)
		return ;
	index = 0;
	while (index < matrix->rows)
	{
		print_row(matrix, index, w);
		printf("\n");
		index++;
	}
	free(w);
}
