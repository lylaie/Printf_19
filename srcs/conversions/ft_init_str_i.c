/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_str_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:14:31 by macbook           #+#    #+#             */
/*   Updated: 2020/03/25 15:11:39 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/ft_printf.h"

/*
 ** Initialisation of the temporary string for the whole integers.
*/

char	*ft_init_str_i(t_t *t_save)
{
	char	*str;
	int		len;
    int 	start;
	char 	filler;

	//printf("******** VALUES ********* :%d|%d\n", t_save->width, t_save->precision);
	//printf("**** FLAGS *** %d\n", t_save->t_flags.zero);
	len = t_save->width >= t_save->precision ? t_save->width : t_save->precision;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
	{
		t_save->t_final.okay = 0;
		return (NULL);
	}
	str[len] = '\0';
	filler = (t_save->t_flags.zero && !t_save->precision && !(t_save->t_flags.dot && !t_save->precision))? '0' : ' ';
	filler = (len == t_save->precision) ? '0' : filler;
	ft_memset(str, filler, len);
	start = t_save->t_flags.minus ? 0 : len - t_save->precision;
	ft_memset(str + start, '0', t_save->precision);
	return (str);
}
