/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:08:34 by macbook           #+#    #+#             */
/*   Updated: 2020/03/14 12:28:06 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/ft_printf.h"

/*
 ** Parsing to check if the value is a flag, a conversion or a numeric value.
*/

const char	*ft_parser(va_list lst, const char *format, t_t *t_save)
{

	++format;	
	while (ft_is_format(*format) && (ft_is_flag(*format) || ft_is_conver(*format) || (*format >= '0' && *format <= '9')))
	{
		if (ft_is_flag(*format))
			format = ft_type_of_flag(*format, format, lst, t_save);
		else if (*format > '0' && *format <= '9')
			format = ft_width_flag(format, t_save);
		else if (ft_is_conver(*format))
			return (format = ft_type_conv(*format, format, lst, t_save));
		else		
				++format;		
	}
	return (format);
}
