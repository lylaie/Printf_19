/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:28:51 by macbook           #+#    #+#             */
/*   Updated: 2020/03/05 14:07:44 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen_base(unsigned long int nb, char *base)
{
	size_t	len_str;
	size_t	len_nb;

	len_str = ft_strlen(base);
	len_nb = 0;
	while (nb >= len_str)
	{
		nb = nb / len_str;
		++len_nb;
	}
	++len_nb;
	return (len_nb);
}
