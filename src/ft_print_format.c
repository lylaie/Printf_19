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

void	ft_print_format(char type, va_list lst)
{
	if (type == 'c')
		ft_putchar((char)va_arg(lst, int));
	else if (type == 's')
		ft_putstr(va_arg(lst, char*));
	else if (type == 'd')
		ft_convert(va_arg(lst, long long int), 10, BASE_10);
	else if (type == 'x' || type == 'p')
	{
		if (type == 'p')
			ft_putstr("0x");
		ft_convert(va_arg(lst, long long int), 16, BASE_16);
	}
	else
		ft_putstr("encore à définir");
}
