/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audumont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:22:42 by audumont          #+#    #+#             */
/*   Updated: 2019/11/15 20:11:26 by audumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_printf.h"

void				ft_convert(long long int nb, int base, char *tank)
{
	long long int	nbr;
	long long int	sign;
	long long int	i;

	nbr = nb & ((~0) >> 1);
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
