/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_of_conversion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:07:46 by macbook           #+#    #+#             */
/*   Updated: 2020/03/26 17:58:54 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/ft_printf.h"

/*
 ** Checks the type of the conversion and put the input inside the final string.
 **
*/

const char	*ft_type_conv(char type, const char *fmt, va_list lst, t_t *t_save)
{
	char	*tmp;
	char	*tmp_s;
	size_t	len_str;
	size_t	len_tmp;
	
	if (type == 'c' || type == 's')
	{
		if (!(tmp = ft_init_str(t_save)))
			return (++fmt);
		(type == 'c') ? tmp = ft_conv_c(tmp, lst, t_save) : 0;
		(type == 's') ? tmp = ft_conv_s(tmp, lst, t_save): 0;
	}
	else if (type == '%')
	{
		if (!(tmp = ft_init_str_p(t_save)))
			return (++fmt);
		tmp = ft_conv_pou(tmp, t_save);	
	}
	else 
		if (!(tmp = ft_init_str_i(t_save)))
			return (++fmt);	
	(type == 'i' || type == 'd') ? tmp = ft_conv_i(tmp, lst, t_save) : 0;
	(type == 'p') ? tmp = ft_conv_p(tmp, lst, t_save) : 0;
	(type == 'x' || type == 'X') ? tmp = ft_conv_x(tmp, lst, t_save, type) : 0;
	(type == 'u') ? tmp = ft_conv_u(tmp, lst, t_save) : 0 ;
	tmp_s = t_save->t_final.f_str;
	t_save->t_final.f_str = ft_strjoin(tmp_s, tmp);
	free(tmp_s);
	free(tmp);
	return (++fmt);
}
