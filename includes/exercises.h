/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exercises.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 11:19:54 by lumugot           #+#    #+#             */
/*   Updated: 2026/07/26 16:01:57 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXERCISES_H
# define EXERCISES_H

# include "vector.h"
# include "matrix.h"
# include <stdio.h>
# include <math.h>

# define EPSILON	1e-6

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

//ex02.c
float		lerp_float(float u, float v, float t);
t_vector	*lerp_vec(t_vector *u, t_vector *v, float t);
t_matrix	*lerp_mat(t_matrix *u, t_matrix *v, float t);
void		ex02(void);

//ex03.c
float		dot(t_vector *u, t_vector *v);
void		ex03(void);

//ex04.c
float		norm_1(t_vector *vector);
float		norm(t_vector *vector);
float		norm_inf(t_vector	*vector);
void		ex04(void);

//ex05.c
 float		angle_cos(t_vector *u, t_vector *v);
void		ex05(void);

//ex06.c
t_vector	*cross_product(t_vector *u, t_vector *v);
void		ex06(void);

//ex07.c
t_vector	*mul_vec(t_matrix *m, t_vector *v);
t_matrix	*mul_mat(t_matrix *m, t_matrix *n);
void		ex07(void);

//ex08.c
float		trace(t_matrix *matrix);
void		ex08(void);

//ex09.c
t_matrix	*transpose(t_matrix *matrix);
void		ex09(void);

//ex10.c
t_matrix	*row_echelon(t_matrix *matrix);
void		ex10(void);

#endif
