/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_star.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 20:30:57 by macbook           #+#    #+#             */
/*   Updated: 2020/05/04 20:37:48 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/ft_printf.h"

/*
** Changes the value of the precision or the width in function of the position
** of the star flag.
** If the width already exists or if dot flag exists, the flag star is
** corresponding to the precision.
*/

const char	*ft_flag_star(const char *format, va_list lst, t_t *t_s)
{
	if ((t_s->t_flags.dot && !t_s->width) || t_s->width)
	{
		t_s->precision = va_arg(lst, int);
		t_s->t_flags.minus = t_s->precision < 0 ? 1 : t_s->t_flags.minus;
		t_s->t_flags.zero = t_s->precision < 0 ? t_s->t_flags.zero--\
		: t_s->t_flags.zero;
		t_s->precision = t_s->precision > 0 ? t_s->precision : 0;
	}
	else
	{
		t_s->width = va_arg(lst, int);
		t_s->t_flags.minus = t_s->width < 0 ? 1 : t_s->t_flags.minus;
		t_s->t_flags.zero = t_s->width < 0 ? 0 : t_s->t_flags.zero;
		t_s->width = t_s->width > 0 ? t_s->width : -t_s->width;
	}
	t_s->t_flags.star++;
	return (++format);
}
