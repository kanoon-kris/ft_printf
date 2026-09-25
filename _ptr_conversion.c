/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ptr_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 08:34:55 by kboonkos          #+#    #+#             */
/*   Updated: 2026/09/25 08:36:49 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

static size_t	_hexlen_address(uintptr_t dec)
{
	size_t	len;

	if (dec == 0)
		len = 1;
	else
	{
		len = 0;
		while (dec > 0)
		{
			dec = dec / 16;
			++len;
		}
	}
	return (len);
}

static char	*_itoa_hex_address(uintptr_t address)
{
	const char	base[] = "0123456789abcdef";
	size_t		len_hex;
	char		*result;

	len_hex = _hexlen_address(address);
	result = (char *)malloc(len_hex + 1);
	if (!result)
		return (NULL);
	*(result + len_hex) = '\0';
	while (len_hex > 0)
	{
		*(result + len_hex - 1) = base[address % 16];
		address = address / 16;
		--len_hex;
	}
	return (result);
}

int	_ptr_conversion(size_t *byte_count, void *arg)
{
	const char	str_null[] = "(nil)";
	const char	prefix_hex[] = "0x";
	char		*str;

	if (arg == NULL)
		*byte_count += write(1, str_null, ft_strlen(str_null));
	else
	{
		*byte_count += write(1, prefix_hex, ft_strlen(prefix_hex));
		str = _itoa_hex_address((uintptr_t)arg);
		*byte_count += write(1, str, ft_strlen(str));
		free(str);
	}
	return (0);
}
