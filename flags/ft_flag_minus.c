/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 20:42:18 by macbook           #+#    #+#             */
/*   Updated: 2020/05/04 22:12:36 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf.h"

/*
** Changes the value of the minus flag.
*/

const char	*ft_flag_minus(const char *format, t_t *t_save)
{
	t_save->t_flags.zero = 0;
	t_save->t_flags.minus = 1;
	return (++format);
}
