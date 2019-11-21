/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_of_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audumont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:12:47 by audumont          #+#    #+#             */
/*   Updated: 2019/11/21 21:05:13 by audumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_lib.h"

int		ft_type_of_flags(const char *format, t_flags flags, char type, va_list lst)
{	
	char		*category[] = {FORMAT_S_FLAGS};
	char		*flags_values;
	char		*tmp;
	int			index;
	int			result;

	flags_values = FORMAT_FLAGS;
	index = 0;
	result = 0;
	tmp = (char *)format;
	while (flags_values[index])
	{
		if (type == flags_values[index])
		{
			if (type == '-')
				flags.minus++;
			else if (type == '0')
				flags.zero++;
			else if (type == '.')
				flags.point++;
			else if (type == '*')
				flags.star++;
			else if (type == 'l' && ++(*tmp) != 'l')
				flags.l++;
			else if (type == 'l' && ++(*tmp) == 'l')
			{
				flags.ll++;
				printf("ll\n");
			}
			else if (type == 'h' && ++*tmp != 'h')
				flags.h++;
			else if (type == 'h' && ++*tmp == 'h')
				flags.hh++;
			else if (type == '\'')
				flags.quote++;
			else if (type == '#')
				flags.sharp++;
			result = 1;
			printf("%s\n", category[index]);
			break;
		}
		index++;
	}
	return (result);
}
