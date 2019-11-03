/* *************************************************************************** */
/*                                                                             */
/*                                                        :::      ::::::::    */
/*   Makefile                                           :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+      */
/*   By: audumont <marvin@42.fr>                    +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+            */
/*   Created: 2019/11/03 12:21:55 by audumont          #+#    #+#              */
/*   Updated: 2019/11/03 12:22:54 by audumont         ###   ########.fr        */
/*                                                                             */
/* *************************************************************************** */

#include "lib_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list lst;
	int	index;
	char 	type;
	

	va_start(lst, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (type = ft_type_of(format))
				ft_print_format(type, lst);
		}
		else
		{
			--format;
			if (*format != '%')
			{
				++format;
				ft_putchar(*format);
			}
			else
				++format;
		}
		++format;
	}
	return (0);
}
