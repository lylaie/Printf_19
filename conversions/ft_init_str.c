/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:02:25 by macbook           #+#    #+#             */
/*   Updated: 2020/05/04 22:07:20 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf.h"

/*
 ** Creation of the first string. Fill up with space for the character and
 ** string conversion.
*/

char	*ft_init_str(t_t *t_save)
{
	int		len;
	char	*str;

	len = t_save->width ? t_save->width : 0;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
	{
		t_save->t_final.okay = 0;
		return (NULL);
	}
	str[len] = '\0';
	ft_memset(str, (t_save->t_flags.zero >= 1) ? '0' : ' ', len);
	return (str);
}
