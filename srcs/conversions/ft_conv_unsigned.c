/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:04:13 by macbook           #+#    #+#             */
/*   Updated: 2020/03/12 12:48:00 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/ft_printf.h"

/*
 ** Converts the argument into an unsigned integer. Stringifies the unsigned
 ** integer into a string. 
*/

char	*ft_conv_u(char	*str, va_list lst, t_t *t_save)
{
	unsigned int	nb;
	int				len_nb;
	char			*str_nb;

	nb = va_arg(lst, unsigned int);
	if (!nb && !t_save->t_flags.star && !t_save->precision && t_save->t_flags.dot)
	{
		if (!(ft_strcmp(str, " ")) && !t_save->width)
		{
			str_nb = ft_strdup("");
			return (ft_free_string(str_nb, str));
		}
		return (str);
	}
	len_nb = ft_intlen_base(nb, BASE_10);
	if (!(str_nb = ft_itoa_base(nb, BASE_10)))
	{
		t_save->t_final.okay = 0;
		return (ft_free_string(NULL, str));
	}
	return (ft_free_string(ft_show_u(str_nb, str, t_save), str_nb));
}
