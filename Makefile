# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: audumont <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/09 15:38:16 by audumont          #+#    #+#              #
#    Updated: 2019/11/09 16:35:25 by audumont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS = src/ft_print_format.c src/ft_putchar.c src/ft_putnbr.c src/ft_putstr.c \
	   src/ft_split.c src/ft_type_of.c src/ft_convert.c
OTHERS = Printest/main.c ft_printf.c

OBJECTS = $(SRCS:%.c=%.o)
O_BJECTS = $(OTHERS:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJECTS) $(O_BJECTS)
	ar rcs $(NAME) $(OBJECTS) $(O_BJECTS)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

fclean : clean
	rm -f $(NAME) $(OBJECTS) $(O_BJECTS)

clean : 
	rm -f $(OBJECTS) $(O_BJECTS)

re : fclean all


