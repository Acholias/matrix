/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 10:35:20 by lumugot           #+#    #+#             */
/*   Updated: 2026/07/19 10:35:21 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stddef.h>

typedef struct s_vector
{
	float	*data;
	size_t	size;
}	t_vector;

t_vector	*neew_vec(size_t size);
t_vector	*from_vec(float *data, size_t size);
void		free_vec(t_vector *vector);

void		print_vec(const t_vector *vector);

#endif
