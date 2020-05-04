/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:22:56 by macbook           #+#    #+#             */
/*   Updated: 2020/05/04 20:30:33 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/ft_printf.h"

/*
** The flag zero exists only if the minus flag doesn't exist. The width's
** value changes to modify the length of the first initialized string.
*/

const char	*ft_flag_zero(const char *format, t_t *t_save)
{
	if (!t_save->t_flags.minus)
		t_save->t_flags.zero++;
	return (++format);
}
