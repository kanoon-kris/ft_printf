/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _udec_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 08:29:36 by kboonkos          #+#    #+#             */
/*   Updated: 2026/09/25 08:31:17 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

static size_t	_count_udec_len(unsigned int nbr)
{
	size_t	len;

	if (nbr == 0)
		return (1);
	len = 0;
	while (nbr > 0)
	{
		nbr /= 10;
		++len;
	}
	return (len);
}

int	_udec_conversion(size_t *byte_count, unsigned int arg)
{
	char	*str;
	size_t	udec_len;

	udec_len = _count_udec_len(arg);
	str = malloc(udec_len + 1);
	if (str == NULL)
		return (1);
	*(str + udec_len) = '\0';
	while (udec_len > 0)
	{
		*(str + udec_len - 1) = (arg % 10) + '0';
		arg /= 10;
		--udec_len;
	}
	*byte_count += write(1, str, ft_strlen(str));
	free(str);
	return (0);
}
