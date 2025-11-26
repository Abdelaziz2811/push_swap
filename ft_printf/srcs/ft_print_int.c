/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahoumi <abahoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:02:49 by abahoumi          #+#    #+#             */
/*   Updated: 2025/10/23 11:37:17 by abahoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	size(int n)
{
	unsigned int	size;

	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
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

int	print_int(va_list *args)
{
	int	n;

	n = va_arg(*args, int);
	ft_putnbr_fd(n, 1);
	return (size(n));
}
