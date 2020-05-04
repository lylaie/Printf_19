# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macbook <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/25 16:01:09 by macbook           #+#    #+#              #
#    Updated: 2020/03/05 13:49:59 by macbook          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = @gcc
HEADER = libft/
CC_FLAGS = -Wall -Werror -Wextra $(OPTION)
OPTION = -I $(HEADER)

SRCS = ft_bzero.c ft_intlen_base.c ft_putstr.c ft_strlcpy.c ft_c_to_str.c \
		ft_itoa_base.c ft_memset.c ft_strcmp.c ft_strjoin.c ft_strlen.c \
		ft_putstr.c ft_strdup.c

OBJECTS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CC_FLAGS) -c -o $@ $<

clean:
	@rm -rf $(OBJECTS)

anc: all clean

fclean: clean
	@rm -rf $(NAME)

re: fclean all
