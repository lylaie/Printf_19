/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audumont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:09:54 by audumont          #+#    #+#             */
/*   Updated: 2019/11/14 21:14:09 by audumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_printf.h"

int					ft_check_format(char type, va_list lst)
{
	int				result;
	long long int	nb;

	result = 0;
	nb = va_arg(lst, long long int);
	if (type == 'p')
	{
		ft_putstr("0x");
		result = 2;
	}
	if (type == 'X')
		ft_convert(nb, 10, BASE_16_U);
	else
		ft_convert(nb, 16, BASE_16);
	result += ft_nblen(nb, 16);
	return (result);
}
