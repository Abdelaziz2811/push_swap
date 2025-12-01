/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahoumi <abahoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:35:01 by abahoumi          #+#    #+#             */
/*   Updated: 2025/12/01 13:30:45 by abahoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int	leading_zeros_count;

	leading_zeros_count = 0;
	while (arg[leading_zeros_count] == '+' || arg[leading_zeros_count] == '-')
		leading_zeros_count++;
	while (arg[leading_zeros_count] == '0'
		&& arg[leading_zeros_count + 1] != '\0')
		leading_zeros_count++;
	if (arg[leading_zeros_count] != '0' && arg[leading_zeros_count] != '\0'
		&& arg[0] == '-')
		leading_zeros_count -= 1;
	return (leading_zeros_count);
}
