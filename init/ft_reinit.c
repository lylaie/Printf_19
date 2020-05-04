/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reinit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:29:15 by macbook           #+#    #+#             */
/*   Updated: 2020/05/04 22:14:59 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf.h"

/*
 ** Reinitialisation of the values of the flags.
*/

void	ft_reinit(t_t *t_all)
{
	ft_bzero(&(t_all->t_flags), sizeof(t_flag));
	t_all->width = 0;
	t_all->precision = 0;
}
