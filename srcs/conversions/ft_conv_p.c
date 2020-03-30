/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 13:57:54 by macbook           #+#    #+#             */
/*   Updated: 2020/03/12 12:54:22 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/ft_printf.h"

char	*ft_conv_p(char *str, va_list lst, t_t *t_save)
{
		unsigned long int pointor;
		char				*tmp_p;
		char				*str_nb;

		pointor = va_arg(lst, unsigned long int);
		tmp_p = ft_itoa_base(pointor, BASE_16);
		if (!pointor && t_save->t_flags.dot && !t_save->precision)
				str_nb = ft_strdup("0x");
		else
				str_nb = ft_strjoin("0x", tmp_p);
		free(tmp_p);
		return (ft_free_string(ft_show_u(str_nb, str, t_save), str_nb));
}
