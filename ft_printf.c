/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audumont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:33:29 by audumont          #+#    #+#             */
/*   Updated: 2019/11/17 15:51:05 by audumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list	lst;
	char	type;
	int		result;
	int		len_flag;

	va_start(lst, format);
	result = 0;
	len_flag = 0;
	while (*format)
	{
		if (*format == '%')
		{
			if ((type = ft_type_of(format)))
				if (type == '0' || type == '.' || type == '-' || type == '*')
					len_flag += ft_check_flags(format, type, lst);
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
