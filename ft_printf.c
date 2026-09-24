/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 23:12:02 by kboonkos          #+#    #+#             */
/*   Updated: 2026/09/25 03:50:13 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

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

int	_ptr_conversion(size_t *byte_count, void *arg)
{
	const char	str_null[] = "(nil)";

	if (arg == NULL)
		*byte_count += write(1, str_null, ft_strlen(str_null));
	else
		;// wip
	return (0);
}

int	_str_conversion(size_t	*byte_count, const char *arg)
{
	const char	str_null[] = "(null)";

	if (arg != NULL)
		*byte_count += write(1, arg, ft_strlen(arg));
	else
		*byte_count += write(1, str_null, ft_strlen(str_null));
	return (0);
}

int	_char_conversion(size_t	*byte_count, int arg)
{
	unsigned char c;

	c = (unsigned char) arg;
	*byte_count += write(1, &c, 1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	byte_count;

	byte_count = 0;
	if ((format == NULL) || (*format == '\0'))
		return (byte_count);
	va_start(args, format);
	while (ft_isprint(*format) == 1)
	{
		if (*format != '%')
			byte_count += write(1, format, 1);
		else
		{
			++format;
			if (*format == 'c')
				_char_conversion(&byte_count, va_arg(args, int));
			else if (*format == 's')
				_str_conversion(&byte_count, va_arg(args, const char *));
			else if (*format == 'p')
				_ptr_conversion(&byte_count, va_arg(args, void *));
			else if (*format == 'd')
				;
			else if (*format == 'i')
				;
			else if (*format == 'u')
				;
			else if (*format == 'x')
				;
			else if (*format == 'X')
				;
			else if (*format == '%')
				byte_count += write(1, format, 1);
		}
		++format;
	}
	va_end(args);
	return (byte_count);
}
