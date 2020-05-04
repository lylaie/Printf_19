/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_of_conversion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:07:46 by macbook           #+#    #+#             */
/*   Updated: 2020/05/04 22:10:29 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf.h"

/*
 ** Checks the type of the conversion and put the input inside the final
 ** string.
*/

static char	*ft_type_conv_2(char *str, char type, va_list lst, t_t *t_save)
{
	if (type == 'i' || type == 'd')
		return (ft_conv_i(str, lst, t_save));
	if (type == 'p')
		return (ft_conv_p(str, lst, t_save));
	if (type == 'x' || type == 'X')
		return (ft_conv_x(str, lst, t_save, type));
	if (type == 'u')
		return (ft_conv_u(str, lst, t_save));
	return (str);
}

static char	*ft_c_or_s(char type, char *str, va_list lst, t_t *t_s)
{
	if (type == 'c' || type == 's')
	{
		if (!(str = ft_init_str(t_s)))
			return (ft_free_string(NULL, str));
		str = (type == 'c') ? ft_conv_c(str, lst, t_s) : \
		ft_conv_s(str, lst, t_s);
	}
	else
	{
		if (!(str = ft_init_str_p(t_s)))
			return (ft_free_string(NULL, str));
		str = ft_conv_pou(str, t_s);
	}
	return (str);
}

const char	*ft_type_conv(char type, const char *fmt, va_list lst, t_t *t_s)
{
	char	*tmp;
	char	*tmp_s;
	size_t	len_str;
	size_t	len_tmp;

	if (type == 'c' || type == 's' || type == '%')
	{
		if (!(tmp = ft_c_or_s(type, tmp, lst, t_s)))
			return (++fmt);
	}
	else
	{
		if (!(tmp = ft_init_str_i(t_s)))
			return (++fmt);
		tmp = ft_type_conv_2(tmp, type, lst, t_s);
	}
	tmp_s = ft_strdup(t_s->t_final.f_str);
	t_s->t_final.f_str = ft_free_double_string(ft_strjoin(tmp_s, tmp), \
	t_s->t_final.f_str, tmp_s);
	free(tmp);
	return (++fmt);
}
