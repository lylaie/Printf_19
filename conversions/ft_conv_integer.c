/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_integer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:51:41 by macbook           #+#    #+#             */
/*   Updated: 2020/05/04 22:06:25 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf.h"

/*
** Converts the signed integer to a string and calculs the lenght of the
** number.
*/

char	*ft_conv_i(char *str, va_list lst, t_t *t_save)
{
	int					nb;
	char				*str_nb;
	unsigned int		nbr;

	nb = va_arg(lst, int);
	if (!nb && !t_save->precision && t_save->t_flags.dot)
	{
		if (!(ft_strcmp(str, " ")) && !t_save->width)
		{
			str_nb = ft_strdup("");
			return (ft_free_string(str_nb, str));
		}
		return (str);
	}
	nbr = (nb >= 0 ? nb : -nb);
	if (!(str_nb = ft_itoa_base(nbr, BASE_10)))
	{
		t_save->t_final.okay = 0;
		return (ft_free_string(NULL, str));
	}
	if (nb < 0)
		return (ft_free_string(ft_show_i(nb, str_nb, str, t_save), str_nb));
	return (ft_free_string(ft_show_u(str_nb, str, t_save), str_nb));
}
