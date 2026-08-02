/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 20:09:34 by lumugot           #+#    #+#             */
/*   Updated: 2026/08/02 22:28:15 by lumugot          ###   ########.fr       */
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

static void	print_sep(char *sep, size_t row, size_t m)
{
	if (row == m)
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

static void	display_op(t_matrix *u, char *op, t_matrix *v, t_matrix *result)
{
	int		*wu;
	int		*wv;
	int		*wr;
	size_t	index;
	size_t	m;

	wu = col_widths(u);
	wv = col_widths(v);
	wr = col_widths(result);
	if (!wu || !wv || ! wr)
	{
		free(wu);
		free(wv);
		free(wr);
		return ;
	}
	m = u->rows / 2;
	index = 0;
	while (index < u->rows)
	{
		print_row(u, index, wu);
		print_sep(op, index, m);
		print_row(v, index, wv);
		print_sep("=", index, m);
		print_row(result, index, wr);
		printf("\n");
		index++;
	}
	free(wu);
	free(wv);
	free(wr);
}

void	display_vec_result(char *op, t_vector *u, t_vector *v, t_vector *result)
{
	t_matrix	*mu;
	t_matrix	*mv;
	t_matrix	*mr;

	mu = vec_to_mat(u);
	mv = vec_to_mat(v);
	mr = vec_to_mat(result);
	if (!mu || !mv || mr)
	{
		free_mat(mu);
		free_mat(mv);
		free_mat(mr);
		return ;
	}
	display_op(mu, op, mv, mr);
	free_mat(mu);
	free_mat(mv);
	free_mat(mr);
}

void	display_mat_result(char *op, t_matrix *u, t_matrix *v, t_matrix *result)
{
	display_op(u, op, v, result);
}

void	display_scalar_result(char *op, t_vector *u, t_vector *v, float result)
{
	t_matrix	*mu;
	t_matrix	*mv;
	int			*wu;
	int			*wv;
	size_t		index;
	size_t		m;
	char		buf[64];

	mu = vec_to_mat(u);
	mv = vec_to_mat(v);
	if (!mu || !mv)
	{
		free_mat(mu);
		free_mat(mv);
		return ;
	}
	wu = col_widths(mu);
	wv = col_widths(mv);
	snprintf(buf, sizeof(buf), "%g", result);
	m = mu->rows / 2;
	index = 0;
	while (index < mu->rows)
	{
		print_row(mu, index, wu);
		print_sep(op, index, m);
		print_row(mv, index, wv);
		if (index == m)
			printf("  =  %s", buf);
		printf("\n");
		index++;
	}
	free(wu);
	free(wv);
	free_mat(mu);
	free_mat(mv);
}
