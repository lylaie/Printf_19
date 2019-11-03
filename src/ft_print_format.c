/* *************************************************************************** */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*    Makefile                                           :+:      :+:    :+:   */
/*                                                      +:+ +:+         +:+    */  
/*    By: audumont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+            */
/*    Created: 2019/10/10 15:13:55 by audumont          #+#    #+#             */
/*   Updated: 2019/10/27 11:40:41 by audumont         ###   ########.fr        */
/*                                                                             */
/* *************************************************************************** */

#include "../lib_printf.h"

void	ft_print_format(char type, va_list lst)
{
	if (type == 'c')
		ft_putchar((char)va_arg(lst, int));
	else if (type == 's')
		ft_putstr(va_arg(lst, char*));
	else if (type == 'd')
		ft_putnbr(va_arg(lst, int));
	else
		ft_putstr("encore à définir");
}
