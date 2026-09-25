/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _str_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 08:37:04 by kboonkos          #+#    #+#             */
/*   Updated: 2026/09/25 09:15:57 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stddef.h>
#include <unistd.h>

int	_str_conversion(size_t	*byte_count, const char *arg)
{
	const char	str_null[] = "(null)";

	if (arg != NULL)
		*byte_count += write(1, arg, ft_strlen(arg));
	else
		*byte_count += write(1, str_null, ft_strlen(str_null));
	return (0);
}
