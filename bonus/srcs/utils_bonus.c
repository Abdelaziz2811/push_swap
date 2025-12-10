/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahoumi <abahoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:35:01 by abahoumi          #+#    #+#             */
/*   Updated: 2025/12/10 15:57:00 by abahoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	contains_duplicate(char **args)
{
	int	i;
	int	k;

	i = 0;
	while (args[i])
	{
		k = i + 1;
		while (args[k])
		{
			if (ft_atoi(args[i]) == ft_atoi(args[k++]))
				return (1);
		}
		i++;
	}
	return (0);
}

int	get_leading_zeros_count(char *arg)
{
	int	zeros_count;

	zeros_count = 0;
	if (arg[zeros_count] == '+' || arg[zeros_count] == '-')
		zeros_count++;
	while (arg[zeros_count] == '0' && arg[zeros_count + 1] != '\0')
		zeros_count++;
	return (zeros_count);
}

int	get_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	is_empty_or_whitespace(char **args)
{
	int	i;
	int	j;

	if (!args)
		return (1);
	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j] && ft_isspace(args[i][j]))
			j++;
		if (!args[i][j])
			return (1);
		i++;
	}
	return (0);
}
