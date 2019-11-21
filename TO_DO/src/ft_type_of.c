/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_of_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audumont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:37:14 by audumont          #+#    #+#             */
/*   Updated: 2019/11/21 19:11:03 by audumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_lib.h"

char	ft_type_of(const char *format, t_flags flags, va_list lst)
{
	char	*value;
	int		index;

	value = FORMAT_VALIDE;
	++format;
	index = 0;
	while (value[index])
	{
		if (*format == value[index])
		{
			printf("%c\n", value[index]);
			if (ft_type_of_flags(format, flags, value[index], lst))
			{
				printf("%c\n", value[index]);
				return (value[index]);
			}
			else
				break;
		}
		index++;
	}
	--format;
	return (0);
}
