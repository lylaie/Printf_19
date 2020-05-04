/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_dot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 20:35:19 by macbook           #+#    #+#             */
/*   Updated: 2020/05/04 22:12:26 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf.h"

const char	*ft_flag_dot(const char *format, t_t *t_s, va_list lst)
{
	++format;
	++t_s->t_flags.dot;
	if (!t_s->precision)
	{
		t_s->precision = 0;
		if (*format == '*')
		{
			t_s->precision = va_arg(lst, int);
			t_s->t_flags.dot = t_s->precision < 0 ? 0 : 1;
			t_s->precision = t_s->precision > 0 ? t_s->precision : 0;
			++format;
			return (format);
		}
		else
		{
			while (*format >= '0' && *format <= '9')
			{
				t_s->precision = t_s->precision * 10 + (*format - '0');
				++format;
			}
		}
		t_s->t_flags.zero = (t_s->t_flags.zero == 1 && !t_s->precision ? -1 :\
		t_s->t_flags.zero);
	}
	return (format);
}
