/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahoumi <abahoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:05:16 by abahoumi          #+#    #+#             */
/*   Updated: 2025/12/09 10:57:04 by abahoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *nptr)
{
	int		i;
	int		sign;
	long	n;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= 13))
		i++;
	sign = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	n = 0;
	while (ft_isdigit(nptr[i]))
		n = n * 10 + (nptr[i++] - '0');
	return (n * sign);
}
