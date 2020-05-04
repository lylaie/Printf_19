/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:12:34 by macbook           #+#    #+#             */
/*   Updated: 2020/05/04 22:14:27 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf.h"

int	ft_is_flag(char type)
{
	char	*flags;

	flags = FLAGS;
	while (*flags)
	{
		if (type == *flags)
			return (1);
		++flags;
	}
	return (0);
}
