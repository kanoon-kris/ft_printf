/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _dec_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 08:32:39 by kboonkos          #+#    #+#             */
/*   Updated: 2026/09/25 08:34:33 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

int	_dec_conversion(size_t *byte_count, int arg)
{
	char	*str;

	str = ft_itoa(arg);
	*byte_count += write(1, str, ft_strlen(str));
	free(str);
	return (0);
}
