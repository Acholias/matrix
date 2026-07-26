/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 17:14:02 by lumugot           #+#    #+#             */
/*   Updated: 2026/07/26 17:32:03 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "exercises.h"

void	print_vec_result(char *op, t_vector *u, t_vector *v, t_vector *result);
void	print_mat_result(char *op, t_matrix *u, t_matrix *v, t_matrix *result);
void	print_scalar_result(char *op, t_vector *u, t_vector *v, float result);

#endif
