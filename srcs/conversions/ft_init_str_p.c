/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_str_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 13:21:48 by macbook           #+#    #+#             */
/*   Updated: 2020/03/25 14:01:27 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/ft_printf.h"

char	*ft_init_str_p(t_t *t_save)
{
	int		len;
	char	*str;
	char	filler;

	len = t_save->width  ? t_save->width : 0;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
	{
		t_save->t_final.okay = 0;
		return (NULL);
	}
	str[len] = '\0';
	filler = (t_save->t_flags.zero) ? '0' : ' ';
	ft_memset(str, filler, len);
	return (str);
}
