/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _upper_hex_conversion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 08:02:21 by kboonkos          #+#    #+#             */
/*   Updated: 2026/09/25 08:06:06 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

static size_t	_hexlen_upper(unsigned int nbr)
{
	size_t	len;

	if (nbr == 0)
		return (1);
	len = 0;
	while (nbr > 0)
	{
		nbr /= 16;
		++len;
	}
	return (len);
}

int	_upper_hex_conversion(size_t *byte_count, unsigned int nbr)
{
	const char	base_16[] = "0123456789ABCDEF";
	char		*str;
	size_t		hex_len;

	hex_len = _hexlen_upper(nbr);
	str = malloc(hex_len + 1);
	if (!str)
		return (1);
	*(str + hex_len) = '\0';
	while (hex_len > 0)
	{
		*(str + hex_len - 1) = base_16[nbr % 16];
		nbr /= 16;
		--hex_len;
	}
	*byte_count += write(1, str, ft_strlen(str));
	free(str);
	return (0);
}
