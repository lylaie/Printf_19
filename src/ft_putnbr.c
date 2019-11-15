/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audumont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:47:45 by audumont          #+#    #+#             */
/*   Updated: 2019/11/15 18:48:19 by audumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_printf.h"

int					ft_putnbr(long long int nb)
{
	long long int	nbr;
	int				i;
	int				sign;

	nbr = nb & ((~0) >> 1);
	sign = nb > 0 ? 1 : -1;
	if (nb < 0)
		ft_putchar('-');
	if (nbr >= 10)
	{
		i = nbr % 10;
		nbr = nbr / 10;
		ft_putnbr(nbr);
		ft_putchar(i + '0');
	}
	else
		ft_putchar(nbr + '0');
	return (nb);
}
