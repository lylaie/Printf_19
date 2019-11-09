/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audumont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:33:40 by audumont          #+#    #+#             */
/*   Updated: 2019/11/09 20:13:13 by audumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../lib_printf.h"

void	ft_print_format(char type, va_list lst)
{
	char *s;

	if (type == 'c')
		ft_putchar((char)va_arg(lst, int));
	else if (type == 's')
		ft_putstr(va_arg(lst, char*));
	else if (type == 'd')
		ft_putnbr(va_arg(lst, int));
	else if (type == 'p')
	{
		s = va_arg(lst, char *);
		printf("%x\n", *s);
		ft_convert( *s ,16, BASE_16);
	}
	else if (type == 'x')
		ft_convert(va_arg(lst, int), 16, BASE_16);
	else
		ft_putstr("encore à définir");
}
