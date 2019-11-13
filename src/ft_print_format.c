/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audumont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:33:40 by audumont          #+#    #+#             */
/*   Updated: 2019/11/10 14:36:37 by audumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../lib_printf.h"


int	ft_print_format(char type, va_list lst)
{
	int result;

	result = 0;
	if (type == 'c')
	{
		ft_putchar((char)va_arg(lst, int));
		result = 1;
	}
	else if (type == 's')
	{
		ft_putstr(va_arg(lst, char*));
		result = ft_strlen(va_arg(lst, char*));
	}
	else if (type == 'd')
	{
		ft_putnbr(va_arg(lst, long long int));
		result = ft_nblen(va_arg(lst, long long int), 10);
	}
	else if (type == 'x' || type == 'p')
	{
		if (type == 'p')
		{
			ft_printf("affichage du début\n");
			ft_putstr("0x");
			result =  2;
		}
		printf("devant\n");
		ft_convert(va_arg(lst, long long int), 16, BASE_16);
		result += ft_nblen(va_arg(lst, long long int), 16);
	}
	else
		ft_putstr("encore à définir");
	return (result);
}
