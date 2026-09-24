# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/22 01:18:07 by kboonkos          #+#    #+#              #
#    Updated: 2026/09/25 02:06:57 by kboonkos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

HEADER = ft_printf.h
LIBFT_HEADER = $(LIBFT_DIR)/libft.h

SRC = ft_printf.c
#SRC = ft_printf.c \
#	  ft_printf_utils.c \
#	  ft_printf_convert.c

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
