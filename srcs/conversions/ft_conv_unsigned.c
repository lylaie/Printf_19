/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:04:13 by macbook           #+#    #+#             */
/*   Updated: 2020/04/30 18:39:55 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/ft_printf.h"

/*
 ** Converts the argument into an unsigned integer. Stringifies the unsigned
 ** integer into a string.
*/

char	*ft_conv_u(char *str, va_list lst, t_t *t_s)
{
	unsigned int	nb;
	int				len_nb;
	char			*str_nb;

	nb = va_arg(lst, unsigned int);
	if (!nb && !t_s->t_flags.star && !t_s->precision && t_s->t_flags.dot)
	{
		if (!(ft_strcmp(str, " ")) && !t_s->width)
			return (ft_free_string(ft_strdup(""), str));
		return (str);
	}
	len_nb = ft_intlen_base(nb, BASE_10);
	if (!(str_nb = ft_itoa_base(nb, BASE_10)))
	{
		t_s->t_final.okay = 0;
		return (ft_free_string(NULL, str));
	}
	return (ft_free_string(ft_show_u(str_nb, str, t_s), str_nb));
}
