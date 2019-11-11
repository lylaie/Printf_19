/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audumont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:33:40 by audumont          #+#    #+#             */
/*   Updated: 2019/11/10 14:36:37 by audumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../lib_printf.h"

int	ft_print_format(char type, va_list lst)
{
	if (type == 'c')
		return (ft_putchar((char)va_arg(lst, int)));
	else if (type == 's')
	{
		ft_putstr(va_arg(lst, char*));
		return (( long int)va_arg(lst, char*));
	}
	else if (type == 'd')
	{
		printf("%lli\n", va_arg(lst, long long int));
		return (ft_putnbr(va_arg(lst, long long int)));
	}
	else if (type == 'x' || type == 'p')
	{
		if (type == 'p')
			ft_putstr("0x");
		return (ft_convert(va_arg(lst, long long int), 16, BASE_16));
	}
	else
		ft_putstr("encore à définir");
	return (va_arg(lst, int));
}
