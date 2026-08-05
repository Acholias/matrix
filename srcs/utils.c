/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 19:44:40 by lumugot           #+#    #+#             */
/*   Updated: 2026/08/05 12:16:03 by lumugot          ###   ########.fr       */
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

float	ft_abs(float x)
{
	if (x < 0)
		return (-x);
	return (x);
}

float	ft_sqrt(float x)
{
	float	res;
	float	prev;

	if (x < 0)
		return (-1);
	if (x == 0)
		return (0);
	res = x / 2.0f;
	prev = 0.0f;
	while (ft_abs(res - prev) > 1e-6f)
	{
		prev = res;
		res = (res + x / res) / 2.0f;
	}
	return (res);
}

float	ft_pow(float x, int n)
{
	float	result;
	int		index;

	if (n == 0)
		return (1);
	result = 1.0f;
	index = 0;
	while (index < n)
	{
		result *= x;
		index++;
	}
	return (result);
}
