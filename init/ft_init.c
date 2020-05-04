/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:18:57 by macbook           #+#    #+#             */
/*   Updated: 2020/05/04 22:14:07 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf.h"

/*
** Initialisation of the final structure. The len of the str equals to 0, the
** string is filled up with 0. The okay value (who show is the combinaison of
** flags and conversion is valid) turns on 1.
*/

void	ft_init(t_f *t_final)
{
	if (!(t_final->f_str = (char*)malloc(sizeof(char))))
		t_final->okay = 0;
	t_final->len = 0;
	ft_bzero(t_final->f_str, 1);
	t_final->okay = 1;
}
