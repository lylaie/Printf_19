/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_integers_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 02:24:17 by macbook           #+#    #+#             */
/*   Updated: 2020/05/04 22:16:03 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf.h"

char	*ft_show_i_5(char *snb, char *str, t_t *t_save, size_t len_nb)
{
	size_t	offset;
	size_t	str_len;
	char	c;
	char	*dash_str;

	str_len = ft_strlen(str);
	offset = ft_show_i_2(str_len, &str, t_save, len_nb);
	dash_str = ft_c_to_str('-');
	if (offset + len_nb < str_len)
	{
		c = str[offset + len_nb];
		ft_strlcpy(str + offset, snb, len_nb + 1);
		str[offset + len_nb] = c;
	}
	else
	{
		dash_str = ft_free_string(ft_c_to_str(str[str_len - 1]), dash_str);
		str = ft_free_string(ft_strjoin(str, dash_str), str);
		ft_strlcpy(str + offset, snb, len_nb + 1);
	}
	return (ft_free_string(str, dash_str));
}
