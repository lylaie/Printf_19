/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audumont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 16:20:43 by audumont          #+#    #+#             */
/*   Updated: 2019/11/17 16:35:11 by audumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_printf.h"


char		ft_type_of_flags(const char *format)
{
	char	*value;
	int		index;
	char	*check;

	value = FORMAT_FLAGS;
	check = (char*)format;
	++check;
	index = 0;
	while (value[index])
	{
		if (*check == value[index])
		{
			if (*check == 'l' && ++(*check) == 'l')
				return ('L');

			if (*check == 'h' && ++(*check) == 'h')
				return ('H');
			index++;
		}
	}
	--check;
	return (0);
}


int			ft_printf_bis(const char * format, ...)
{
	va_list	lst;
	int		result;
	char	type;
	
	va_start(lst, format);
	result = 0;
	while (*format)
	{
		if (*format == '%')
		{
			if (type == ft_type_of_flags(format) > 0)
				printf("%c\n", type);
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

