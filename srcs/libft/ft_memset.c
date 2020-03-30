/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:14:15 by macbook           #+#    #+#             */
/*   Updated: 2020/03/08 20:54:46 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*dest;
	size_t			index;

	dest = (unsigned char*) b;
	index = 0;
	while (index < len)
	{
		dest[index] = (unsigned char) c;
		++index;
	}
	b = (void*)dest;
	return (b);
}
