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
	char *s;
	int i;
	char c;
	char **strs;
	int	index;

	va_start(lst, format);
	//strs = ft_split(format,'%');
	while (*format)
	{
		if (*format == '%')
			ft_type_of(format);
		++format;
	}
	index = 0;
	/*while (strs[index])
	{
		ft_putstr(strs[index]);
		ft_putchar('\n');
		index++;
	}*/
	return (0);
}
