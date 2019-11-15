/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audumont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 20:14:24 by audumont          #+#    #+#             */
/*   Updated: 2019/11/15 20:19:37 by audumont         ###   ########.fr       */
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
	while (value[index])
	{
		if (type == value[index])
		{
			if (type == '-')
			{
			}
			else if (type == '0')
			else if (type == '.')
			else if (type == '*')
		}
			len++;
		else
			break;
		index+;
	}
	return (len);
}
