/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 22:40:39 by lumugot           #+#    #+#             */
/*   Updated: 2026/08/03 10:26:21 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLI_H
# define CLI_H

# include "matrix.h"
# include "vector.h"
# include "utils.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef enum e_exercise
{
	EX00,
	EX01,
	EX02,
	EX03,
	EX04,
	EX05,
	EX06,
	EX07,
	EX08,
	EX09,
	EX10,
	EX11,
	EX12,
	EX13,
	UNKNOWN,
}	t_exercise;

typedef	struct s_cli
{
	t_exercise	ex;
	t_matrix	**mats;
	size_t		count;
	float		*scalars;
	size_t		count_scalar;
	bool		has_scalar;
}	t_cli;

t_cli	*parse_args(int argc, char **argv);
void	free_cli(t_cli *cli);
void	helper_usage(void);

#endif
