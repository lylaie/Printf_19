/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:14:39 by macbook           #+#    #+#             */
/*   Updated: 2020/05/04 22:06:04 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf.h"

/*
 ** Conversion of arguments into character type. Return the join of the initia-
 ** lised string (str) and the string conversion of the character (c).
*/

static char	*ft_minus_c(char *str_c, char *str, size_t str_len)
{
	char	c;

	c = str[str_len];
	ft_strlcpy(str + str_len - 1, str_c, 2);
	str[str_len] = c;
	return (str);
}

static char	*ft_c_no_minus(char *str_c, char *str, size_t str_len)
{
	char	c;

	c = str[1];
	ft_strlcpy(str, str_c, 2);
	str[1] = c;
	return (str);
}

char		*ft_conv_c(char *str, va_list lst, t_t *t_save)
{
	char	c;
	char	*str_c;
	size_t	str_len;

	c = (char)va_arg(lst, int);
	if (!c)
	{
		c = -1;
		t_save->t_final.okay = 2;
	}
	str_len = ft_strlen(str);
	str_c = ft_c_to_str(c);
	if (!str_len)
		str = ft_free_string(ft_strdup(str_c), str);
	else
	{
		if (!t_save->t_flags.minus && c)
			str = ft_minus_c(str_c, str, str_len);
		else if (c)
			str = ft_c_no_minus(str_c, str, str_len);
	}
	return (ft_free_string(str, str_c));
}
