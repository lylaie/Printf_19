/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_of_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audumont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:12:47 by audumont          #+#    #+#             */
/*   Updated: 2019/11/21 19:27:06 by audumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_lib.h"

int		ft_type_of_flags(const char *format, t_flags flags, char type, va_list lst)
{	
	char		*category[] = {FORMAT_S_FLAGS};
	char		*flags_values;
	char		*cate;
	int			index;
	int			result;

	flags_values = FORMAT_FLAGS;
	index = 0;
	result = 0;
	while (flags_values[index])
	{
		if (type == flags_values[index])
		{
			cate = category[index];
			flags.(category[index])++;
			printf("%d\n", flags.category[index]);
			printf("%s\n", category[index]);
			result = 1;
		}
		index++;
	}
	return (result);
}
