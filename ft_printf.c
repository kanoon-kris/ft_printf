/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 23:12:02 by kboonkos          #+#    #+#             */
/*   Updated: 2026/11/25 22:52:48 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>

// Conversions to be handled:
// cspdiuxX%
// %c: single character
// %s: a string
// %p: (void *) argument to be printed in hex format
// %d: a decimal base 10
// %i: an integer in base 10
// %u: an unsigned decimal in base 10 number
// %x: hex num in lowercase format
// %X: hex num in uppercase format
// %%: a percent sign

static void	_conversion_handler(const char **format, va_list *args,
		size_t *byte_count)
{
	*format += 1;
	if (**format == 'c')
		_char_conversion(byte_count, va_arg(*args, int));
	else if (**format == 's')
		_str_conversion(byte_count, va_arg(*args, const char *));
	else if (**format == 'p')
		_ptr_conversion(byte_count, va_arg(*args, void *));
	else if ((**format == 'd') || (**format == 'i'))
		_dec_conversion(byte_count, va_arg(*args, int));
	else if (**format == 'u')
		_udec_conversion(byte_count, va_arg(*args, unsigned int));
	else if (**format == 'x')
		_lower_hex_conversion(byte_count, va_arg(*args, unsigned int));
	else if (**format == 'X')
		_upper_hex_conversion(byte_count, va_arg(*args, unsigned int));
	else if (**format == '%')
		*byte_count += write(1, *format, 1);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	size_t		byte_count;
	const char	**ptr;

	if (format == NULL)
		return (-1);
	byte_count = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format != '%')
			byte_count += write(1, format, 1);
		else
		{
			ptr = &format;
			_conversion_handler(ptr, &args, &byte_count);
		}
		++format;
	}
	va_end(args);
	return (byte_count);
}
