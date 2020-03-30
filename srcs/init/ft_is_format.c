/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:15:16 by macbook           #+#    #+#             */
/*   Updated: 2020/02/25 17:17:01 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/ft_printf.h"

int	ft_is_format(char type)
{
	// Should accept other whitespaces ?
	if (type == '\n' || type == '\0')
		return (0);
	return (1);
}
