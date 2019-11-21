/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audumont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:32:03 by audumont          #+#    #+#             */
/*   Updated: 2019/11/21 21:20:31 by audumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_lib.h"

int				ft_printf(const char *format, ...)
{
	va_list		lst;
	int			result;
	char		type;
	t_flags		flags;

	va_start(lst, format);
	result = 0;
	ft_initialize_flags(flags);
	while (*format)
	{
		ft_initialize_flags(flags);
		if (*format == '%')
		{
			if ((type = ft_type_of(format, flags, lst)>0))
					result += ft_print_format(format, type, lst, flags);	
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
