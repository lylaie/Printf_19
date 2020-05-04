# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: audumont <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/29 20:29:19 by audumont          #+#    #+#              #
#    Updated: 2020/04/30 19:23:35 by macbook          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = @gcc
HEADER = lib/
CC_FLAGS = -Wall -Werror -Wextra $(OPTION)
OPTION = -I $(HEADER)
LIBFT_P = srcs/libft/

CONV_P = srcs/conversions/
FLAG_P = srcs/flags/
INIT_P = srcs/init/
SHOW_P = srcs/shows/
CLEAN_P = srcs/cleaning/

SRCS = ft_printf.c \
		$(CONV_P)ft_conv_c.c $(CONV_P)ft_conv_hex.c $(CONV_P)ft_conv_s.c \
		$(CONV_P)ft_conv_integer.c $(CONV_P)ft_conv_unsigned.c \
		$(CONV_P)ft_init_str.c $(CONV_P)ft_init_str_i.c \
		$(CONV_P)ft_type_of_conversion.c $(CONV_P)ft_conv_p.c \
		$(CONV_P)ft_conv_pourcent.c $(CONV_P)ft_init_str_p.c\
		$(CONV_P)ft_conv_s2.c\
		\
		$(FLAG_P)ft_flag_dot.c $(FLAG_P)ft_flag_minus.c \
		$(FLAG_P)ft_flag_star.c $(FLAG_P)ft_flag_zero.c \
		$(FLAG_P)ft_type_of_flag.c $(FLAG_P)ft_width_flag.c \
		\
		$(INIT_P)ft_init.c $(INIT_P)ft_parser.c $(INIT_P)ft_width_flag.c \
		$(INIT_P)ft_is_flag.c $(INIT_P)ft_is_conver.c $(INIT_P)ft_is_format.c\
		$(INIT_P)ft_reinit.c \
		\
		$(SHOW_P)ft_show_integer.c $(SHOW_P)ft_show_unsigned.c \
		$(SHOW_P)ft_show_integers_2.c\
		\
		$(CLEAN_P)ft_free_tt.c $(CLEAN_P)ft_free_string.c \
		$(CLEAN_P)ft_free_struct.c

OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJECTS)
	make -C $(LIBFT_P) all
	cp $(LIBFT_P)/libft.a $(NAME)
	@ar rc $(NAME) $(OBJECTS)


clean:
	make -C $(LIBFT_P) clean
	@rm -rf $(OBJECTS)

anc : all clean

fclean : clean
	rm -rf $(NAME)
	rm -rf $(LIBFT_P)/libft.a

re: fclean all
