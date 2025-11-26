/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahoumi <abahoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:03:20 by abahoumi          #+#    #+#             */
/*   Updated: 2025/10/23 11:38:37 by abahoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_nbr(unsigned int nbr)
{
	if (nbr >= 10)
		put_nbr(nbr / 10);
	ft_putchar_fd((nbr % 10) + '0', 1);
}

static int	size(unsigned int unbr)
{
	int	size;

	if (unbr == 0)
		return (1);
	size = 0;
	while (unbr > 0)
	{
		size++;
		unbr /= 10;
	}
	return (size);
}

int	print_uint(va_list *args)
{
	unsigned int	unbr;

	unbr = va_arg(*args, unsigned int);
	put_nbr(unbr);
	return (size(unbr));
}
