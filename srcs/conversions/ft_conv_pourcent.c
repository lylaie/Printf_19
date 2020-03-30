/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_pourcent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:29:05 by macbook           #+#    #+#             */
/*   Updated: 2020/03/09 09:49:28 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/ft_printf.h"

char	*ft_conv_pou(char *str, t_t *t_save)
{
		char	*tmp_p;
		size_t	len_str;
		char	tmp_c;

		len_str = ft_strlen(str);
		tmp_p = ft_c_to_str('%');
		if (!len_str)
				return (ft_free_string(tmp_p, str));
		if (t_save->t_flags.minus)
		{
				tmp_c = str[1];
				ft_strlcpy(str, tmp_p, 2);
				str[1] = tmp_c;
		}
		else
				ft_strlcpy(str + len_str - 1, tmp_p, 2);
		free(tmp_p);
		return (str);
}
