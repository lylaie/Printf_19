/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 19:20:59 by macbook           #+#    #+#             */
/*   Updated: 2020/04/30 20:15:08 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/ft_printf.h"

char		*ft_conv_no_min_wid(char *str, char *tmp, t_t *t_save, size_t qq)
{
	size_t	start;

	start = 0;
	if (t_save->width)
	{
		start = t_save->width > qq ? t_save->width - qq : 0;
		ft_strlcpy(str + start, tmp, qq + 1);
	}
	else
		ft_strlcpy(str, tmp, qq + 1);
	return (str);
}

static char	*ft_no_minus2(char *str, char *tmp, t_t *t_save, size_t len_str)
{
	char	*tmp1;

	if (!(tmp1 = malloc(sizeof(char) * (t_save->precision + 1))))
	{
		t_save->t_final.okay = 0;
		return (ft_free_string(ft_strdup(""), str));
	}
	tmp1[t_save->precision] = '\0';
	ft_memset(tmp1, '0', t_save->precision);
	ft_strlcpy(tmp1, tmp, t_save->precision + 1);
	return (ft_free_string(tmp1, str));
}

char		*ft_conv_no_minus(char *str, char *tmp, t_t *t_s, size_t lstr)
{
	size_t	start;
	size_t	len_tmp;
	char	*tmp1;

	len_tmp = ft_strlen(tmp);
	start = 0;
	if (t_s->precision && len_tmp > t_s->width)
	{
		if (lstr > t_s->precision)
		{
			start = (lstr - t_s->precision > 0) ? lstr - t_s->precision : 0;
			ft_strlcpy(str + start, tmp, t_s->precision + 1);
		}
		else
			str = ft_no_minus2(str, tmp, t_s, lstr);
	}
	else
	{
		if (t_s->precision)
			start = t_s->precision > len_tmp ? len_tmp : t_s->precision;
		else
			start = len_tmp;
		str = ft_conv_no_min_wid(str, tmp, t_s, start);
	}
	return (str);
}
