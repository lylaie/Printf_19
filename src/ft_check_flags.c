/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audumont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 20:14:24 by audumont          #+#    #+#             */
/*   Updated: 2019/11/16 02:40:02 by audumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_printf.h"

int	ft_check_flags(char type, va_list lst)
{
	int	index;
	char *value;
	int len;
	
	value = FORMAT_FLAGS;
	index = 0;
	len = 0;
	while (value[index] != '\0')
	{
		if (type == value[index])
		{
			if (type == '-')
				printf("%s\n", "moins détecté");
			else if (type == '0')
				printf("%s\n", "affichage du zéro");
			else if (type == '.')
				printf("%s\n", "affichage du point");
			else if (type == '*')
				printf("%s\n", "affichage de l'étoile");
			len++;
			break;
		}
		index++;
	}
	return (len);
}
