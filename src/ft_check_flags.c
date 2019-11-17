/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audumont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 20:14:24 by audumont          #+#    #+#             */
/*   Updated: 2019/11/17 16:21:21 by audumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_printf.h"

int	ft_check_zero(char *format, char type, va_list lst)
{
	if (++format != '.' && format != '*' && (!(format >= 0 && format <= 9)))
		return (0); 
	if (format == '.')
	{
		if (++format != '*' && (!(format >= 0 && format <= 9)))
			return (0);
		if (++format == '*')
			return
	}
}

int	ft_check_flags(char *format, char type, va_list lst)
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
			{
				printf("%s\n", "moins détecté");
				if (&format == 0 || (!(&format >= 0 && &format<= 9)))
					break;
				while (&format >= 0 && &format <= 9)
				{
					len = len * 10 + (&format +'0');
					format++;
				}
			}
			else if (type == '0')
			{
				if (++format != '.')
					return (len);
				printf("%s\n", "affichage du zéro");
				else
				{
					if (++format != '.' || (format >= 1 && format <= 9))
						break;
					if (format == '.' && ++format == "*")
						len = va_list(lst, int);
					if (format == '.' && (++format >= 0 && format <= 9)
							|| (format >= 0 && format <= 9))
					{
						while (format >= 0 && format <= 9)
						{	
							len = len * 10 + (&format +'0');
							format++;
						}
					}
				}
			}
			else if (type == '.')
				printf("%s\n", "affichage du point");
			else if (type == '*')
				printf("%s\n", "affichage de l'étoile");
			break;
		}
		index++;
	}
	return (len);
}
