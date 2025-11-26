/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahoumi <abahoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:46:02 by abahoumi          #+#    #+#             */
/*   Updated: 2025/10/23 10:48:06 by abahoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/includes/libft.h"
# include <stdarg.h>

int	ft_printf(const char *format, ...);

int	print_char(va_list *args);
int	print_str(va_list *args);
int	print_ptr(va_list *args);
int	print_int(va_list *args);
int	print_uint(va_list *args);
int	print_hex_low(va_list *args);
int	print_hex_upp(va_list *args);
int	print_char_fd(char c, int fd);

#endif