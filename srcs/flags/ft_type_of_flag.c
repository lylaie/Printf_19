/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_of_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:11:36 by macbook           #+#    #+#             */
/*   Updated: 2020/03/14 12:27:46 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/ft_printf.h"

/*
 ** Checks the type of flag and calls the associated function. Returns a pointer
 ** of format who moves in function of the length of the flag.
*/

const char	*ft_type_of_flag(char type, const char *fmt, va_list lst, t_t *t_save)
{
	if (type == '*')
		fmt = ft_flag_star(fmt, lst, t_save);
	if (type == '0')
		fmt = ft_flag_zero(fmt, t_save);
	if (type == '-')
		fmt = ft_flag_minus(fmt, t_save);
	if (type == '.')
		fmt = ft_flag_dot(fmt, t_save, lst);
	return (fmt);
}
