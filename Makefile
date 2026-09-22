# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/22 01:18:07 by kboonkos          #+#    #+#              #
#    Updated: 2026/09/22 02:35:31 by kboonkos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ft_printf.o: ft_printf.c
	cc -Wall -Wextra -Werror -c ft_printf.c -o ft_printf.o

clean:
	rm ft_printf.o

fclean:


re:


.PHONY: all clean fclean re
