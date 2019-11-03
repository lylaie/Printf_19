/*# **************************************************************************** #*/
/*#                                                                              #*/
/*#                                                         :::      ::::::::    #*/
/*#    Makefile                                           :+:      :+:    :+:    #*/
/*#                                                     +:+ +:+         +:+      #*/
/*#    By: audumont <marvin@42.fr>                    +#+  +:+       +#+         #*/
/*#                                                 +#+#+#+#+#+   +#+            #*/
/*#    Created: 2019/10/10 15:13:55 by audumont          #+#    #+#              #*/
/*#    Updated: 2019/10/27 11:40:41 by audumont         ###   ########.fr        #*/
/*#                                                                              #*/
/*# **************************************************************************** #*/

#ifndef LIB_PRINTF_H
# define LIB_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
int	ft_printf(const char *str, ...);

char	**ft_split(const char *str, char c);
void	ft_type_of(const char *str);

#endif
