/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:56:15 by macbook           #+#    #+#             */
/*   Updated: 2020/04/30 18:53:01 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/ft_printf.h"

/*
 ** Converts the argument into a string depends the value of the type. If the
 ** type equals to 'x', the base used is BASE_16.
*/

char	*ft_conv_x(char *str, va_list lst, t_t *t_s, char type)
{
	unsigned int	nb;
	char			*str_nb;

	nb = va_arg(lst, unsigned int);
	if (!nb && !t_s->t_flags.star && !t_s->precision && t_s->t_flags.dot)
	{
		if (!(ft_strcmp(str, " ")) && !t_s->width)
		{
			str_nb = ft_strdup("");
			return (ft_free_string(str_nb, str));
		}
		return (str);
	}
	if (!(str_nb = ft_itoa_base(nb, type == 'x' ? BASE_16 : BASE_16_X)) &&\
	nb != 0)
	{
		t_s->t_final.okay = 0;
		return (ft_free_string(NULL, str));
	}
	return (ft_free_string(ft_show_u(str_nb, str, t_s), str_nb));
}
