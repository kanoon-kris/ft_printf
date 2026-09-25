# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/22 01:18:07 by kboonkos          #+#    #+#              #
#    Updated: 2026/09/25 09:53:36 by kboonkos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

HEADER = ft_printf.h
LIBFT_HEADER = $(LIBFT_DIR)/libft.h

SRC = ft_printf.c \
		_upper_hex_conversion.c \
		_lower_hex_conversion.c \
		_udec_conversion.c \
		_dec_conversion.c \
		_ptr_conversion.c \
		_str_conversion.c \
		_char_conversion.c

OBJS = ${SRC:.c=.o}

CC = cc
AR = ar
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g3
INCLUDE = -I . -I $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) rcs $(NAME) $(OBJS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c $(HEADER) $(LIBFT_HEADER)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re $(LIBFT)
