/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audumont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:31:40 by audumont          #+#    #+#             */
/*   Updated: 2019/11/15 20:27:18 by audumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_printf.h"

int					ft_unit_format(char type, va_list lst)
{
	long long int	nb;
	long long int	unitmax;

	unitmax = UNIT_MAX;
	nb = va_arg(lst, long long int);
	if (nb > 0)
	{
		ft_putnbr(nb);
		return (ft_nblen(nb, 10));
	}
	else
	{
		ft_putnbr(unitmax - nb);
		return (ft_nblen(unitmax - nb, 10));
	}
}

int					ft_int_format(char type, va_list lst)
{
	long long int	nb;

	nb = va_arg(lst, long long int);
	ft_putnbr(nb);
	return (ft_nblen(nb, 10));
}

int					ft_check_octal(va_list lst)
{
	int				result;
	long long int	nb;

	result = 0;
	nb = va_arg(lst, long long int);
	ft_convert(nb, 8, BASE_8);
	result += ft_nblen(nb, 8);	
}

int					ft_print_format(char type, va_list lst)
{
	int				result;
	long long int	nb;
	char			*str1;

	result = 0;
	if (type == 'c')
		result = ft_putchar((char)va_arg(lst, int));
	else if (type == 's')
	{
		str1 = va_arg(lst, char*);
		ft_putstr(str1);
		result = ft_strlen(str1);
	}
	else if (type == 'd' || type == 'i')
		result = ft_int_format(type, lst);
	else if (type == 'x' || type == 'p' || type == 'X')
		result += ft_check_format(type, lst);
	else if (type == 'u')
		result += ft_unit_format(type, lst);
	else if (type == '%')
		ft_putchar('%');
	else if (ft_check_flags(type, lst))
		ft_putchar("coucou");
	else if (type == 'o')
		result += ft_check_octal(lst);
	return (result);
}
