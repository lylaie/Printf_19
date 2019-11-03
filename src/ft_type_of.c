/* *************************************************************************** */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*    ft_type_of.c                                       :+:      :+:    :+:   */
/*                                                      +:+ +:+         +:+    */  
/*    By: audumont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+            */
/*    Created: 2019/10/10 15:13:55 by audumont          #+#    #+#             */
/*   Updated: 2019/10/27 11:40:41 by audumont         ###   ########.fr        */
/*                                                                             */
/* *************************************************************************** */

#include "../lib_printf.h"

/*
static char value[];

value = "sdxc%";

static char *msg[5];

msg = {"string à compléter", "digit", "nombre hexa", "character", "simple pourcentage"};*/

void	ft_type_of(const char *format)
{
	char *value;
	char *msg[] = {"string", "digit", "hexa", "character", "pourcentage"};
	int index;

	value = "sdxc%";
	++format;
	index = 0;
	while (value[index])
	{
		if (*format == value[index])
		{
			ft_putstr("valeur à afficher: ");
			ft_putstr(msg[index]);
			ft_putchar('\n');
			break;
		}
		index++;
	}
	--format;
}
