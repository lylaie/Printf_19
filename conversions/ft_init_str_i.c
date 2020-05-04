/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_str_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:14:31 by macbook           #+#    #+#             */
/*   Updated: 2020/05/04 22:07:32 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf.h"

/*
 ** Initialisation of the temporary string for the whole integers.
*/

char	*ft_init_str_i(t_t *t_s)
{
	char	*str;
	int		len;
	int		start;
	char	filler;

	len = t_s->width >= t_s->precision ? t_s->width : t_s->precision;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
	{
		t_s->t_final.okay = 0;
		return (NULL);
	}
	str[len] = '\0';
	filler = (t_s->t_flags.zero && !t_s->precision && !(t_s->t_flags.dot &&\
	!t_s->precision)) ? '0' : ' ';
	filler = (len == t_s->precision) ? '0' : filler;
	ft_memset(str, filler, len);
	start = t_s->t_flags.minus ? 0 : len - t_s->precision;
	ft_memset(str + start, '0', t_s->precision);
	return (str);
}
