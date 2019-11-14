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
	unsigned int nb;
	char *str1;

	result = 0;
	if (type == 'c')
	{
		ft_putchar((char)va_arg(lst, int));
		result = 1;
	}
	else if (type == 's')
	{
		str1  = va_arg(lst, char*);
		ft_putstr(str1);
		result = ft_strlen(str1);
	}
	else if (type == 'd' || type == 'i')
	{
		printf("coucou\n");
		ft_putnbr(va_arg(lst, long long int));
		result = ft_nblen(va_arg(lst, long long int), 10);
	}
	else if (type == 'x' || type == 'p' || type == 'X') 
	{
		if (type == 'p')
		{
			ft_printf("affichage du début\n");
			ft_putstr("0x");
			result =  2;
		}
		printf("devant\n");
		if (type == 'X')
			ft_convert(va_arg(lst,long long int), 10, BASE_16_U);
		ft_convert(va_arg(lst, long long int), 16, BASE_16);
		result += ft_nblen(va_arg(lst, long long int), 16);
	}
	else if (type == 'u')
	{
		printf("salut\n");
		nb = va_arg(lst, int) > 0 ? va_arg(lst, int) : -va_arg(lst, int);

		ft_putnbr((long long int)nb);
		result += ((long long int) nb, 10);	
	}
	else if (type == '%')
		ft_putchar('%');
	else
		ft_putstr("encore à définir");
	return (result);
}
