/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 02:07:03 by kboonkos          #+#    #+#             */
/*   Updated: 2026/09/25 08:08:20 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"

int	ft_printf(const char *format, ...);
int	_upper_hex_conversion(size_t *byte_count, unsigned int nbr);
int	_lower_hex_conversion(size_t *byte_count, unsigned int nbr);
int	_udec_conversion(size_t *byte_count, unsigned int arg);
int	_dec_conversion(size_t *byte_count, int arg);
int	_ptr_conversion(size_t *byte_count, void *arg);
int	_str_conversion(size_t *byte_count, const char *arg);
int	_char_conversion(size_t *byte_count, int arg);

#endif
