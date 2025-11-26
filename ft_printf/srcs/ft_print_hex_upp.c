/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_upp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahoumi <abahoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:02:58 by abahoumi          #+#    #+#             */
/*   Updated: 2025/10/24 09:47:55 by abahoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_hex(unsigned int n, int *total_chars)
{
	static char	*hex = "0123456789ABCDEF";

	if (n >= 16)
		put_hex(n / 16, total_chars);
	*total_chars += print_char_fd(hex[n % 16], 1);
}

int	print_hex_upp(va_list *args)
{
	int	total_chars;

	total_chars = 0;
	put_hex(va_arg(*args, int), &total_chars);
	return (total_chars);
}
