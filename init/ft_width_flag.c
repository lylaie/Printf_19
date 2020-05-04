/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:18:44 by macbook           #+#    #+#             */
/*   Updated: 2020/05/04 22:15:19 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf.h"

/*
 ** Calculs of the width or the precision when the parser finds numbers.
*/

const char	*ft_width_flag(const char *format, t_t *t_save)
{
	if (!t_save->width || (t_save->t_flags.star && !t_save->t_flags.dot))
	{
		t_save->width = 0;
		while (*format >= '0' && *format <= '9')
		{
			t_save->width = t_save->width * 10 + (*format - '0');
			++format;
		}
	}
	else
	{
		while (*format >= '0' && *format <= '9')
		{
			t_save->precision = t_save->precision * 10 + (*format - '0');
			++format;
		}
	}
	return (format);
}
