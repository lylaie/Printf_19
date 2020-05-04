/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_integer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:53:43 by macbook           #+#    #+#             */
/*   Updated: 2020/05/04 22:15:35 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf.h"

/*
**  Shows the integer conversion of signed numbers. Depends the lenght and the
**	 value of the precision, an another tmp string is initialised and filled up
**	 with total_len or len_str 'O'.
**
**  If the flag minus exists but not the dot flags, the length of the value is
**  equals to len_str + 1 and the copy of the str_nb starts from str[1].
*/

static size_t	ft_show_i_4(size_t slen, char **str, t_t *t_s, size_t lnb)
{
	size_t		offset;
	char		*dash_str;

	offset = 0;
	dash_str = ft_c_to_str('-');
	str[0] = ft_free_double_string(ft_strjoin(dash_str, str[0]), str[0], dash_str);
	offset = slen - lnb + 1;
	return (offset);
}

static size_t	ft_show_i_3(size_t str_len, char **str, t_t *t_s, size_t lnb)
{
	size_t		offset;

	offset = 0;
	if (t_s->width == str_len && str_len != t_s->precision)
	{
		if (t_s->precision)
		{
			offset = str_len - (t_s->precision >= lnb ? t_s->precision : lnb);
			str[0][offset - 1] = '-';
			offset = str_len - lnb;
		}
		else if (t_s->t_flags.zero >= 1 && str_len > lnb && !t_s->t_flags.dot)
		{
			str[0][0] = '-';
			offset = str_len - lnb;
		}
		else
		{
			str[0][str_len - lnb - 1] = '-';
			offset = str_len - lnb;
		}
	}
	else if (t_s->precision == str_len)
		return (ft_show_i_4(str_len, str, t_s, lnb));
	return (offset);
}

size_t			ft_show_i_2(size_t str_len, char **str, t_t *t_save, size_t lnb)
{
	size_t		offset;
	size_t		offset_minus;

	offset = 1;
	if (t_save->t_flags.minus)
	{
		str[0][0] = '-';
		if (str_len != t_save->precision && t_save->precision >= lnb)
			offset += t_save->precision - lnb;
		if (str_len == t_save->precision)
			offset += str_len - lnb;
	}
	else
		offset = ft_show_i_3(str_len, str, t_save, lnb);
	return (offset);
}

char			*ft_show_i(long long int nb, char *snb, char *str, t_t *t_save)
{
	size_t		lnb;
	size_t		slen;
	char		*dash_str;
	size_t		offset;
	char		c;

	dash_str = ft_c_to_str('-');
	slen = ft_strlen(str);
	lnb = ft_strlen(snb);
	if (slen >= lnb + 1)
		str = ft_show_i_5(snb, str, t_save, lnb);
	else
	{
		if (slen == t_save->precision && !t_save->width && slen == lnb + 1)
		{
			ft_strlcpy(str + slen - lnb, snb, lnb + 1);
			snb = ft_free_string(ft_strjoin(dash_str, str), snb);
			str = ft_free_string(ft_strdup(snb), str);
		}
		else
			str = ft_free_string(ft_strjoin(dash_str, snb), str);
	}
	return (ft_free_string(str, dash_str));
}
