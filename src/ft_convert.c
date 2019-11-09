/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audumont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:22:42 by audumont          #+#    #+#             */
/*   Updated: 2019/11/09 20:08:14 by audumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_printf.h"

void		ft_convert(int nb, int base, char *tank)
{
	unsigned int nbr;
	int		sign;
	int		i;

	nbr = nb & ((~0) >> 1);
	sign = nb > 0 ? 1 : -1;
	if (nb < 0)
		ft_putchar('-');
	if (nbr >= base)
	{
		i = nbr % base;
		nbr = nbr / base;
		ft_convert(nbr, base, tank);
		ft_putchar(tank[i]);
	}
	else
		ft_putchar(tank[nbr]);
}
