/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahoumi <abahoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:46:07 by abahoumi          #+#    #+#             */
/*   Updated: 2025/10/24 10:28:27 by abahoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	index_of(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	return (-1);
}

static int	specifier_handler(char specifier, va_list *args)
{
	static char		specs[] = {'c', 's', 'p', 'd', 'i', 'u', 'x', 'X', '%'};
	static int		(*handlers[])(va_list *) = {print_char, print_str,
		print_ptr, print_int, print_int, print_uint,
		print_hex_low, print_hex_upp};
	int				indx;
	int				total_chars;

	indx = index_of(specifier, specs);
	total_chars = handlers[indx](args);
	return (total_chars);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	i;
	int				total_chars;

	if (!format)
		return (-1);
	i = 0;
	total_chars = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!format[++i])
				return (-1);
			if (format[i] && ft_strchr("cspdiuxX", format[i]))
				total_chars += specifier_handler(format[i++], &args);
			else
				total_chars += print_char_fd(format[i++], 1);
		}
		else
			total_chars += print_char_fd(format[i++], 1);
	}
	va_end(args);
	return (total_chars);
}
