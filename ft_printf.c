# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: audumont <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/03 12:21:55 by audumont          #+#    #+#              #
#    Updated: 2019/11/03 12:22:54 by audumont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#include "printf_lib.h"

int	ft_printf(const char *format, ...)
{
	va_list lst;
	char *s;
	int i;
	char c;

	va_start(lst, format);
	while (*format)
	{
		if (*format == 's')
		{
			s = va_args(lst, char *);
			ft_putstr(s);		
		}
		else if (*format == 'd')
		{
			i = va_args(lst, int);
			ft_putnbr(i);
		}
		else if (*format == 'c')
		{
			c = (char)va_args(lst, char);
			ft_puthcar(c);
		}
		++format;
	}
	return (0);
}
