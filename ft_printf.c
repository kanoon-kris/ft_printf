/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 23:12:02 by kboonkos          #+#    #+#             */
/*   Updated: 2026/09/24 05:01:58 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

//static size_t	_strlen(const char *s)
//{
//	size_t	count;
//
//	count = 0;
//	while (*s++ != '\0')
//		++count;
//	return (count);
//}

int	ft_printf(const char *format, ...)
{
	size_t	index;
	size_t	byte_written;
	size_t	byte_total;
	unsigned char	specifier_mode;
	va_list	args;
	//unsigned char	*p_char;
	void	*p_all;

	index = 0;
	byte_total = 0;
	specifier_mode = 0;
	va_start(args, format);
	//p_char = malloc(1);
	while (*(format + index) != '\0')
	{
		if ((*(format + index) == '%') && (specifier_mode == 0))
			specifier_mode = 1;
		else if ((specifier_mode == 1) && (*(format + index) == 'c'))
		{
//			*p_char = (unsigned char) va_arg(args, unsigned int);
//			byte_written = write(1, p_char, 1);
			p_all = malloc(sizeof(char));
			*p_all = va_arg(args, char);
			byte_written = write(1, (char *)p_all, 1);
		}
		else if ((specifier_mode == 1) && (*(format + index) == 's'))
		{
			//wip
		}
		else
		{
			byte_written = write(1, (format + index), 1);
			if (byte_written < 0)
				return (byte_written);
		}
		byte_total += byte_written;
		++index;
	}
	va_end(args);
	return (byte_total);
}
#include <stdio.h>
int	main(void)
{
	const char	text[] = "IT WORKS HAHAHA\n";
	ft_printf("ft: "); ft_printf(text);
	printf("og: "); printf(text);
// %c: single character
	const char	letter = 'x';
	ft_printf("ft: "); ft_printf("%c\n", letter);
	printf("og: "); printf("%c\n", letter);
// %s: a string
//	const char	s[] = "42Bangkok";
//	ft_printf("ft: "); ft_printf("%s\n", s);
//	printf("og: "); printf("%s\n", s);
// %p: (void *) argument to be printed in hex format
// %d: a decimal base 10
// %i: an integer in base 10
// %u: an unsigned decimal in base 10 number
// %x: hex num in lowercase format
// %X: hex num in uppercase format
// %%: a percent sign
	return (0);
}
