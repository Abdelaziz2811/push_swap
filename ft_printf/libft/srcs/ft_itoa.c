/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahoumi <abahoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 09:47:50 by abahoumi          #+#    #+#             */
/*   Updated: 2025/10/16 11:49:40 by abahoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	get_size(int n)
{
	unsigned int	size;

	size = 0;
	if (n < 0)
	{
		n = -n;
		size++;
	}
	while (n > 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char			*nbr_s;
	unsigned int	size;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	size = get_size(n);
	nbr_s = malloc(sizeof(char) * (size + 1));
	if (!nbr_s)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		nbr_s[0] = '-';
	}
	nbr_s[size] = '\0';
	size -= 1;
	while (n > 0)
	{
		nbr_s[size--] = (n % 10) + '0';
		n /= 10;
	}
	return (nbr_s);
}
