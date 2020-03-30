/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_conver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:13:53 by macbook           #+#    #+#             */
/*   Updated: 2020/02/25 17:21:50 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/ft_printf.h"

int	ft_is_conver(char type)
{
	char	*conver;

	conver = CONVERSION;
	while (*conver)
	{
		if (type == *conver)
			return (1);
		++conver;
	}
	return (0);
}
