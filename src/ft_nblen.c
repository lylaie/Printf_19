/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audumont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:05:56 by audumont          #+#    #+#             */
/*   Updated: 2019/11/14 21:06:57 by audumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_printf.h"

int					ft_nblen(long long int nb, int base)
{
	int				len;
	long long int	nbr;

	len = 0;
	nbr = nb & ((~0) >> 1);
	while (nbr >= base)
	{
		nbr = nbr / base;
		len++;
	}
	len++;
	return (len);
}
