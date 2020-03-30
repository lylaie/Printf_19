/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:18:56 by macbook           #+#    #+#             */
/*   Updated: 2020/03/26 18:16:50 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/ft_printf.h"

/*
 ** Fill up the string in function of the width, the precision or the lenght of
 ** the tmp string. If the tmp string equals to 0, the function returns the
 ** value "(null)". If the tmp string is empty, the returns is also an empty
 ** string.
 **
 ** Some cases exist : with the dot flag, no precision and a " " string, the
 ** function returns an empty string too.
*/

static char	*ft_conv_no_min_wid(char *str, char *tmp, t_t *t_save, size_t qq)
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

static char	*ft_conv_no_minus(char *str, char *tmp, t_t *t_save, size_t len_str)
{
	size_t	start;
	size_t	len_tmp;
	char	*tmp1;

	len_tmp = ft_strlen(tmp);
	start = 0;
	if (t_save->precision && len_tmp > t_save->width) 
	{
		if (len_str > t_save->precision)
		{
				start = (len_str - t_save->precision) > 0 ? len_str - t_save->precision\
				: 0;
				ft_strlcpy(str + start, tmp, t_save->precision + 1);
		}
		else
		{
			if (!(tmp1 = malloc(sizeof(char) * (t_save->precision + 1))))
			{
				t_save->t_final.okay = 0;
				tmp1 = ft_strdup("");
				return (ft_free_string(tmp1, str));
			}
			tmp1[t_save->precision] = '\0';
			ft_memset(tmp1, '0', t_save->precision);
			ft_strlcpy(tmp1, tmp, t_save->precision + 1);
			free(str);
			str = tmp1;
		}
	}
	else
	{
		if (t_save->precision)
			start = t_save->precision > len_tmp ? len_tmp : t_save->precision;
		else
			start = len_tmp;
		str = ft_conv_no_min_wid(str, tmp, t_save, start);
	}
	return (str);
}

static	char	*ft_conv_minus(char *str, char *tmp, t_t *t_save, size_t len_tmp)
{
	char	tmp_c;
	int		size;
		
	if (t_save->precision < len_tmp && t_save->precision)
	{
		if (ft_strlen(str) < len_tmp)
		{
				free(str);
				size = (t_save->width > t_save->precision) ? t_save->width: t_save->precision;
				if (!(str = malloc(sizeof(char) * size + 1)))
					return (NULL);	
				ft_memset(str, ' ', size);	
				str[size] = '\0';
		}		
		tmp_c = str[t_save->precision];
		ft_strlcpy(str, tmp, t_save->precision + 1);
		if (t_save->width >= t_save->precision)
			str[t_save->precision] = tmp_c;
	}
	else
		ft_strlcpy(str, tmp, len_tmp + 1);
	return (str);
}

char	*ft_conv_s(char *str, va_list lst, t_t *t_save)
{
	char	*tmp;
	size_t	len_str;
	size_t		len_tmp;
	char	*tmp_s;
	char	c;

	tmp_s = va_arg(lst, char *);
	if (!tmp_s)
		tmp_s = "(null)";
	tmp = ft_strdup(tmp_s);
	len_str = ft_strlen(str);
	if (t_save->t_flags.dot && !t_save->precision)
	{
		if ((ft_strcmp(str, " ") == 0) && !t_save->width)
		{
			free(tmp);	
			tmp = ft_strdup("");
			return (ft_free_string(tmp, str));
		}
		else
			return (ft_free_string(str, tmp));
	}
	len_tmp = ft_strlen(tmp);
	if (len_tmp >= len_str && len_tmp >= t_save->width && (!t_save->precision || len_tmp <= t_save->precision))
		return (ft_free_string(tmp,str));
	if (!t_save->t_flags.minus)
		str = ft_conv_no_minus(str, tmp, t_save, len_str);
	else
	{
		if (len_str >= len_tmp)
			c = str[len_tmp];
		str = ft_conv_minus(str, tmp, t_save, len_tmp);
		if (t_save->width && len_str >= len_tmp)
			str[len_tmp] = c;
	}
	free(tmp);
	return (str);
}
