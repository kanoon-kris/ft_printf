/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _char_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 08:38:37 by kboonkos          #+#    #+#             */
/*   Updated: 2026/09/25 08:39:12 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>

int	_char_conversion(size_t	*byte_count, int arg)
{
	unsigned char	c;

	c = (unsigned char) arg;
	*byte_count += write(1, &c, 1);
	return (0);
}
