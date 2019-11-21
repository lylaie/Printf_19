/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audumont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:17:51 by audumont          #+#    #+#             */
/*   Updated: 2019/11/21 21:36:27 by audumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_lib.h"



int			ft_int_format(va_list lst, t_flags flags)
{
		
}

int			ft_print_format(const char *format, char type, va_list lst, \
		t_flags flags)
{
	int		result;
	char	*str1;

	result = 0;
	if (type == 'c')
		result += ft_putchar((char)va_arg(lst, int));
	else if (type == 's')
	{
		str1 = va_arg(lst, char*);
		ft_putstr(str1);
		result = ft_strlen(str1);
	}
	else if (type == 'd' || type == 'i')
		result = ft_int_format(lst, flags);
	else if (type == 'x' || type == 'p' || type == 'x')
		result += ft_check_format(type, lst);
	else if (type == 'u')
		result += ft_unit_format(lst);
	else if (type == '%')
		ft_puchar('%');
	else if (type == 'o')
		result += ft_check_octal(lst);
	else
		ft_putstr("rien trouvé");
	return (result);
}
