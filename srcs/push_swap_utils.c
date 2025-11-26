/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahoumi <abahoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:15:43 by abahoumi          #+#    #+#             */
/*   Updated: 2025/11/23 17:54:33 by abahoumi         ###   ########.fr       */
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

int	parse_args(char **args)
{
	int		i;
	int		j;
	char	*s_nbr;

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
		s_nbr = ft_itoa(ft_atoi(args[i]));
		if (ft_strlen(s_nbr) != ft_strlen(args[i]))
			return (free(s_nbr), 0);
		free(s_nbr);
		i++;
	}
	return (!contains_duplicate(args));
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}
