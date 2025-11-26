/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahoumi <abahoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:15:43 by abahoumi          #+#    #+#             */
/*   Updated: 2025/11/22 15:53:15 by abahoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_args(char **args)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (args[i])
	{
		j = 0;
		if (args[i][j] == '-' || args[i][j] == '+')
			j++;
		while (args[i][j] && ft_isdigit(args[i][j]))
			j++;
		if (args[i][j])
			return (0);
		if (ft_strlen(ft_itoa(ft_atoi(args[i]))) != ft_strlen(args[i]))
			return (0);
		k = i + 1;
		while (args[k])
		{
			if (ft_atoi(args[i]) == ft_atoi(args[k++]))
				return (0);
		}
		i++;
	}
	return (1);
}
