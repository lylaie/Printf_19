/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:38:53 by macbook           #+#    #+#             */
/*   Updated: 2020/03/12 19:38:41 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/ft_printf.h"

/*
 ** Show the stringified unsigned integer. Depends of the precision and the
 ** length of the number, an another tmp string will be initialised, filled up
 ** with '0' character (not null).
*/

char	*ft_show_u(char *str_nb, char *str, t_t *t_save)
{
	size_t	len_str;
	size_t	len_nb;
	size_t	offset;
	char	tmp;


	len_nb = ft_strlen(str_nb);
	len_str = ft_strlen(str);
	offset = 0;
	if (len_str >= len_nb)
	{
		if (t_save->t_flags.minus && t_save->precision && len_str == t_save->width)
			offset = (t_save->precision >= len_nb ? t_save->precision - len_nb : 0);
		if (t_save->t_flags.minus && t_save->precision == len_str)
				offset = len_str - len_nb;
		else if (!t_save->t_flags.minus)
			offset = len_str - len_nb;	
		tmp = str[offset + len_nb];
		ft_strlcpy(str + offset, str_nb, len_nb + 1);
		str[offset + len_nb] = tmp;
	}
	else
	{
		free(str);
		str = ft_strdup(str_nb);
	}
	return (str);
}
