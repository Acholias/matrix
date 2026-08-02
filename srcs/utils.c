/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 19:44:40 by lumugot           #+#    #+#             */
/*   Updated: 2026/08/02 23:39:46 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	exercise_header(char *label, char *name)
{
	size_t	index;
	size_t	len;

	printf("\n%s  " BOLD  "%s" RESET "\n", label, name);
	len = strlen(name) + 12;
	index = 0;
	while (index < len)
	{
		printf("━");
		index++;
	}
	printf("\n\n");
}
