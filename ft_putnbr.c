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

#include "lib_printf.h"

void	ft_putnbr(int nb)
{
	unsigned int nbr;
	int i;
	int sign;

	nbr = nb & ((~0) >> 1);
	sign = nb > 0 ? 1 : -1;
	if (nb < 0)
		ft_putchar('-');
	if (nbr >= 10)
	{
		i = nbr % 10;
		nbr = nbr /10;
		ft_putnbr(nbr);
		ft_putchar(i + '0');
	}
	else
		ft_putchar(nbr +'0');
}
