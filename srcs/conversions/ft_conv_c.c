/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:14:39 by macbook           #+#    #+#             */
/*   Updated: 2020/03/27 17:50:36 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/ft_printf.h"

/*
 ** Conversion of arguments into character type. Return the join of the initia-
 ** lised string (str) and the string conversion of the character (c).
*/

char	*ft_conv_c(char *str, va_list lst, t_t *t_save)
{
		char	c;
		char	*str_c;
		size_t	str_len;
		char	d;

		c = (char)va_arg(lst, int);
		if (!c)
		{
			c = -1;
			t_save->t_final.okay = 2;
		}	
		str_len = ft_strlen(str);
		str_c = ft_c_to_str(c);
		if (!str_len)
		{
			free(str);
			str = ft_strdup(str_c);
		}
		else
		{
			if (!t_save->t_flags.minus && c)
			{
				c = str[str_len];
				ft_strlcpy(str + str_len - 1, str_c, 2);
				str[str_len] = c;
			}
			else if (c)
			{
				
				d = str[1];
				ft_strlcpy(str, str_c, 2);
				str[1] = d;
			}
		}
		return (ft_free_string(str, str_c));
}
