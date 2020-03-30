/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_integer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:53:43 by macbook           #+#    #+#             */
/*   Updated: 2020/03/27 17:32:18 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/ft_printf.h"

/*
 **  Shows the integer conversion of signed numbers. Depends the lenght and the
 **	 value of the precision, an another tmp string is initialised and filled up
 **	 with total_len or len_str 'O'.
 **
 **  If the flag minus exists but not the dot flags, the length of the value is
 **  equals to len_str + 1 and the copy of the str_nb starts from str[1].
 **
 **
*/

static size_t ft_show_i_2(size_t str_len, char **str, t_t *t_save, size_t len_nb)
{
		size_t	offset;
		size_t	offset_minus;
		char	*tmp;
		char	*dash_str;

		dash_str = ft_c_to_str('-');
		offset = 0;
		if (t_save->t_flags.minus)
		{
				str[0][0] = '-';
				++offset;
				if (str_len != t_save->precision && t_save->precision >= len_nb)
						offset += t_save->precision - len_nb;
				if (str_len == t_save->precision)
						offset += str_len - len_nb;
		}
		else
		{
			if (t_save->width == str_len && str_len != t_save->precision)
			{
				if (t_save->precision)
				{
					offset = str_len - (t_save->precision >= len_nb ? t_save->precision : len_nb);
					str[0][offset - 1] = '-';
					offset = str_len - len_nb;
				}
				else if (t_save->t_flags.zero >= 1 && str_len > len_nb && !t_save->t_flags.dot)
				{
					str[0][0] = '-';
					offset = str_len - len_nb;
				}
				else
				{
						str[0][str_len - len_nb - 1] = '-';
						offset = str_len - len_nb;
				}		
			}
			else if (t_save->precision == str_len)
			{
				str[0] = ft_strjoin(dash_str, str[0]);
				offset = str_len - len_nb + 1;
			}	
		}
		free(dash_str);
		return (offset);
}

char	*ft_show_i(long long int nb, char *str_nb, char *str, t_t *t_save)
{
	size_t	len_nb;
	size_t	str_len;
	char	*dash_str;
	size_t	offset;
	char	c;

	dash_str = ft_c_to_str('-');
	str_len = ft_strlen(str);
	len_nb 	= ft_strlen(str_nb);
	if (str_len >= len_nb + 1)
	{		
		offset = ft_show_i_2(str_len, &str, t_save, len_nb);
		if (offset + len_nb < str_len)
		{
			c = str[offset + len_nb];
			ft_strlcpy(str + offset, str_nb, len_nb + 1);
			str[offset + len_nb] = c;
		}
		else
		{
			free(dash_str);
			dash_str = ft_c_to_str(str[str_len - 1]);
			str = ft_strjoin(str, dash_str);
			ft_strlcpy(str + offset, str_nb, len_nb + 1);
		}

	}
	else
	{
		if (str_len == t_save->precision && !t_save->width && str_len == len_nb + 1)
		{
				ft_strlcpy(str + str_len - len_nb, str_nb, len_nb + 1);
				free(str_nb);
				str_nb = ft_strjoin(dash_str, str);
				free(str);
				str = ft_strdup(str_nb);
		}
		else
		{
				free(str);
				str = ft_strjoin(dash_str, str_nb);
		}		
	}
	return (ft_free_string(str, dash_str));
}
