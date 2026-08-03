/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 17:14:02 by lumugot           #+#    #+#             */
/*   Updated: 2026/08/03 10:39:14 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "vector.h"
# include "matrix.h"


t_vector	*mat_to_vec(t_matrix *matrix);
t_matrix	*vec_to_mat(t_vector *vector);
void		display_vec(t_vector *vector);
void		display_mat(t_matrix *martix);
void		display_vec_result(char *op, t_vector *u, t_vector *v, t_vector *result);
void		display_mat_result(char *op, t_matrix *u, t_matrix *v, t_matrix *result);
void		display_scalar_result(char *op, t_vector *u, t_vector *v, float result);
void		display_mat_scl(t_matrix *u, float scalar, t_matrix *result);

#endif
