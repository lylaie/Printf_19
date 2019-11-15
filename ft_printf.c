/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audumont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:33:29 by audumont          #+#    #+#             */
/*   Updated: 2019/11/14 20:50:08 by audumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list	lst;
	char	type;
	int		result;

	va_start(lst, format);
	result = 0;
	while (*format)
	{
		if (*format == '%')
		{
			if ((type = ft_type_of(format)))
				result += ft_print_format(type, lst);
			++format;
		}
		else
		{
			if (*format != '%')
			{
				ft_putchar(*format);
				result++;
			}
		}
		++format;
	}
	return (result);
}
