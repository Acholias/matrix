/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 11:08:25 by lumugot           #+#    #+#             */
/*   Updated: 2026/08/03 12:47:07 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/exercises.h"
#include "../includes/cli.h"

static void	run_exercises(t_cli *cli)
{
	switch (cli->ex)
	{
		case EX00: ex00(cli); break ;
		case EX01: ex01(cli); break ;
		case EX02: ex02(cli); break ;
		case EX03: ex03(cli); break ;
		case EX04: ex04(cli); break ;
		case EX05: ex05(cli); break ;
		case EX06: ex06(cli); break ;
		case EX07: ex07(cli); break ;
		case EX08: ex08(cli); break ;
		case EX09: ex09(cli); break ;
		case EX10: ex10(cli); break ;
		case EX11: ex11(cli); break ;
		// case EX12: ex12(cli); break ;
		// case EX13: ex13(cli); break ;
		// 
		default:	break ;
	}
}

int	main(int argc, char **argv)
{
	t_cli	*cli;

	cli = parse_args(argc, argv);
	if (!cli)
		return (1);
	run_exercises(cli);
	free_cli(cli);
	return (0);
}
