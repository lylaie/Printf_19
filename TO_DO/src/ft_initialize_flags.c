/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audumont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:43:41 by audumont          #+#    #+#             */
/*   Updated: 2019/11/21 18:45:07 by audumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_lib.h"

void ft_initialize_flags(t_flags flags)
{
	printf("coucou\n");
	flags.minus = 0;
	flags.zero = 0;
	flags.point = 0;
	flags.star = 0;
	flags.l = 0;
	flags.ll = 0;
	flags.h = 0;
	flags.hh = 0;
	flags.quote = 0;
	flags.sharp = 0;
	flags.plus = 0;
	printf("au revoir\n");
}
