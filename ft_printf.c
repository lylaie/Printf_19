/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audumont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:33:29 by audumont          #+#    #+#             */
/*   Updated: 2019/11/09 16:39:10 by audumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list lst;
	char 	type;
	int	result;

	va_start(lst, format);
	while (*format)
	{
		if (*format == '%')
		{
			if ((type = ft_type_of(format)))
			{
				result = ft_print_format(type, lst);
			}
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
	return (result);
}
