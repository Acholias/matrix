/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 10:35:10 by lumugot           #+#    #+#             */
/*   Updated: 2026/07/19 11:01:40 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include <stddef.h>
# include <stdbool.h>

typedef struct s_matrix
{
	float	**data;
	size_t	rows;
	size_t	cols;
}	t_matrix;

t_matrix	*new_mat(size_t	rows, size_t cols);
t_matrix	*from_mat(float **data, size_t rows, size_t cols);
void		free_mat(t_matrix *matrix);

void		print_mat(const t_matrix *matrix);
bool		mat_is_square(const t_matrix *matrix);

#endif
