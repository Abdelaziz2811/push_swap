/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahoumi <abahoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:03:12 by abahoumi          #+#    #+#             */
/*   Updated: 2025/11/22 15:47:53 by abahoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_hex(unsigned long n, int *total_chars)
{
	static char	*hex = "0123456789abcdef";

	if (n >= 16)
		put_hex(n / 16, total_chars);
	*total_chars += print_char_fd(hex[n % 16], 1);
}

int	print_ptr(va_list *args)
{
	void	*addr;
	int		total_chars;

	addr = va_arg(*args, void *);
	total_chars = 0;
	if (!addr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	put_hex((unsigned long)addr, &total_chars);
	return (total_chars + 2);
}
