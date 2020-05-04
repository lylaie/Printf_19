/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:18:56 by macbook           #+#    #+#             */
/*   Updated: 2020/05/04 22:06:52 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf.h"

/*
** Fill up the string in function of the width, the precision or the lenght of
** the tmp string. If the tmp string equals to 0, the function returns the
** value "(null)". If the tmp string is empty, the returns is also an empty
** string.
** Some cases exist : with the dot flag, no precision and a " " string, the
** function returns an empty string too.
*/

static char	*ft_conv_minus(char *str, char *tmp, t_t *t_s, size_t len_tmp)
{
	char	tmp_c;
	int		s;

	if (t_s->precision < len_tmp && t_s->precision)
	{
		if (ft_strlen(str) < len_tmp)
		{
			free(str);
			s = (t_s->width > t_s->precision) ? t_s->width : t_s->precision;
			if (!(str = malloc(sizeof(char) * s + 1)))
				return (NULL);
			ft_memset(str, ' ', s);
			str[s] = '\0';
		}
		tmp_c = str[t_s->precision];
		ft_strlcpy(str, tmp, t_s->precision + 1);
		if (t_s->width >= t_s->precision)
			str[t_s->precision] = tmp_c;
	}
	else
		ft_strlcpy(str, tmp, len_tmp + 1);
	return (str);
}

static char	*ft_conv_s2(char *str, char *tmp, t_t *t_save, size_t ltmp)
{
	size_t	lstr;
	char	c;

	lstr = ft_strlen(str);
	if (lstr >= ltmp)
		c = str[ltmp];
	str = ft_conv_minus(str, tmp, t_save, ltmp);
	if (t_save->width && lstr >= ltmp)
		str[ltmp] = c;
	return (str);
}

static char	*ft_conv_s3(char *str, t_t *t_save, char *tmp)
{
	if ((ft_strcmp(str, " ") == 0) && !(t_save->width))
		return (ft_free_double_string(ft_strdup(""), tmp, str));
	else
		return (ft_free_string(str, tmp));
}

char		*ft_conv_s(char *str, va_list lst, t_t *t_s)
{
	char	*tmp;
	size_t	lstr;
	size_t	ltmp;

	tmp = va_arg(lst, char *);
	if (!tmp)
		tmp = "(null)";
	tmp = ft_strdup(tmp);
	lstr = ft_strlen(str);
	if (t_s->t_flags.dot && !t_s->precision)
		return (ft_conv_s3(str, t_s, tmp));
	ltmp = ft_strlen(tmp);
	if (ltmp >= lstr && ltmp >= t_s->width && (!t_s->precision ||\
	ltmp <= t_s->precision))
		return (ft_free_string(tmp, str));
	if (!t_s->t_flags.minus)
		str = ft_conv_no_minus(str, tmp, t_s, lstr);
	else
		str = ft_conv_s2(str, tmp, t_s, ltmp);
	return (ft_free_string(str, tmp));
}
