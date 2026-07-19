/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exercises.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 11:19:54 by lumugot           #+#    #+#             */
/*   Updated: 2026/07/19 13:48:16 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXERCISES_H
# define EXERCISES_H

# include "vector.h"
# include "matrix.h"
# include <stdio.h>
# include <math.h>

// ex00.c
void		vec_add(t_vector *u, const t_vector *v);
void		vec_sub(t_vector *u, const t_vector *v);
void		vec_scl(t_vector *u, float a);
void		mat_add(t_matrix *u, const t_matrix *v);
void		mat_sub(t_matrix *u, const t_matrix *v);
void		mat_scl(t_matrix *u, float a);
void		ex00(void);

//ex01.c
t_vector	*linear_combination(t_vector **u, float *coefs, size_t len);
void		ex01(void);

//ex02
float		lerp_float(float u, float v, float t);
t_vector	*lerp_vec(t_vector *u, t_vector *v, float t);
t_matrix	*lerp_mat(t_matrix *u, t_matrix *v, float t);
void		ex02(void);

#endif
