/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audumont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:22:42 by audumont          #+#    #+#             */
/*   Updated: 2019/11/10 14:34:26 by audumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_printf.h"

long long int		ft_convert(long long int nb, int base, char *tank)
{
	long long int  nbr;
	long long int		sign;
	long long int		i;
	long long int result;

	nbr = nb & ((~0) >> 1);
	sign = nb > 0 ? 1 : -1;
	result = 0;
	if (nb < 0)
		ft_putchar('-');
	if (nbr >= base)
	{
		i = nbr % base;
		nbr = nbr / base;
		result = result * 10 + i;
		ft_convert(nbr, base, tank);
		ft_putchar(tank[i]);
	}
	else
		ft_putchar(tank[nbr]);
	result = result * 10 + nbr;
	return (result * sign);
}
