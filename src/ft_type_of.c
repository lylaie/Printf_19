/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_of.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audumont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:42:38 by audumont          #+#    #+#             */
/*   Updated: 2019/11/15 18:43:20 by audumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_printf.h"

char		ft_type_of(const char *format)
{
	char	*value;
	int		index;

	value = FORMAT_CHAR;
	++format;
	index = 0;
	while (value[index])
	{
		if (*format == value[index])
			return (value[index]);
		index++;
	}
	--format;
	return (0);
}
