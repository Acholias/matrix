/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 22:44:37 by lumugot           #+#    #+#             */
/*   Updated: 2026/08/02 23:46:27 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cli.h"

void	helper_usage(void)
{
	printf(BOLD "USAGE\n" RESET);
	printf("    ./matrix <exercise> [matrix1] [matrix2...]\n\n");
	printf(BOLD "EXERCISES\n" RESET);
	printf("    " GREEN "ex00" RESET "    Add, Subtract and Scale\n");
	printf("    " GREEN "ex01" RESET "    Linear Combination\n");
	printf("    " GREEN "ex02" RESET "    Linear Interpolation\n");
	printf("    " GREEN "ex03" RESET "    Dot Product\n");
	printf("    " GREEN "ex04" RESET "    Norm\n");
	printf("    " GREEN "ex05" RESET "    Cosine\n");
	printf("    " GREEN "ex06" RESET "    Cross Product\n");
	printf("    " GREEN "ex07" RESET "    Matrix Multiplication\n");
	printf("    " GREEN "ex08" RESET "    Trace\n");
	printf("    " GREEN "ex09" RESET "    Transpose\n");
	printf("    " GREEN "ex10" RESET "    Row Echelon Form\n");
	printf("    " GREEN "ex11" RESET "    Determinant\n");
	printf("    " GREEN "ex12" RESET "    Inverse\n");
	printf("    " GREEN "ex13" RESET "    Rank\n\n");
	printf(BOLD "FORMAT\n" RESET);
	printf("    Vecteur  : " YELLOW "\"1,2,3\"" RESET "\n");
	printf("    Matrice  : " YELLOW "\"1,2;3,4\"" RESET "  " GREY "(virgule = colonne, point-virgule = ligne)\n" RESET);
	printf("\n");
	printf(BOLD "EXAMPLES\n" RESET);
	printf("    " GREY "# Dot product\n" RESET);
	printf("    ./matrix ex03 \"1,2,3\" \"4,5,6\"\n\n");
	printf("    " GREY "# Addition de matrices\n" RESET);
	printf("    ./matrix ex00 \"1,2;3,4\" \"5,6;7,8\"\n\n");
}

static t_exercise	str_to_exercise(char *str)
{
	static const char	*names[] = { "ex00", "ex01", "ex02", "ex03",
									"ex04", "ex05", "ex06","ex07", "ex08", "ex09", 
									"ex10", "ex11", "ex12", "ex13", NULL };
	int	index;

	index = 0;
	while (names[index])
	{
		if (strcmp(str, names[index]) == 0)
			return ((t_exercise)index);
		index++;
	}
	return (UNKNOWN);
}

static size_t	count_char(char *str, char c)
{
	size_t	count;
	size_t	index;

	count = 0;
	index = 0;
	while (str[index])
	{
		if (str[index] == c)
			count++;
		index++;
	}
	return (count);
}

static t_matrix	*parse_matrix(char *str)
{
	t_matrix	*mat;
	size_t		rows;
	size_t		cols;
	size_t		i;
	size_t		j;
	char		*ptr;
	char		*end;

	rows = count_char(str, ';') + 1;
	cols = count_char(str, ',') / rows + 1;
	mat = new_mat(rows, cols);
	if (!mat)
		return (NULL);
	ptr = str;
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			mat->data[i][j] = strtof(ptr, &end);
			if (ptr == end)
			{
				free_mat(mat);
				return (NULL);
			}
			ptr = end;
			if (*ptr == ',' || *ptr == ';')
				ptr++;
			j++;
		}
		i++;
	}
	return (mat);
}

t_cli	*parse_args(int argc, char **argv)
{
	t_cli		*cli;
	t_exercise	ex;
	int			index;

	if (argc < 2)
	{
		helper_usage();
		return (NULL);
	}
	ex = str_to_exercise(argv[1]);
	if (ex == UNKNOWN)
	{
		printf(RED "Error: unknown exercise '%s'\n\n", argv[1]);
		helper_usage();
		return (NULL);
	}
	cli = malloc(sizeof(t_cli));
	if (!cli)
		return (NULL);
	cli->ex = ex;
	cli->count = argc - 2;
	cli->mats = malloc(sizeof(t_matrix *) * (cli->count + 1));
	if (!cli->mats)
	{
		free(cli);
		return (NULL);
	}
	index = 0;
	while (index < (int)cli->count)
	{
		cli->mats[index] = parse_matrix(argv[index + 2]);
		if (!cli->mats[index])
		{
			printf(RED "Erreur" RESET " : format invalide pour '%s'\n", argv[index + 2]);
			printf(GREY "Format attendu : \"1,2;3,4\"\n" RESET);
			while (index-- < 0)
				free_mat(cli->mats[index]);
			free(cli->mats);
			free(cli);
			return (NULL);
		}
		index++;
	}
	return (cli);
}

void	free_cli(t_cli *cli)
{
	size_t	index;

	index = 0;
	while (index < cli->count)
	{
		free_mat(cli->mats[index]);
		index++;
	}
	free(cli->mats);
	free(cli);
}
