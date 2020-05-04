/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:36:04 by macbook           #+#    #+#             */
/*   Updated: 2020/04/30 16:37:27 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *str, const char *src, size_t size)
{
	unsigned int	index;

	index = 0;
	if (!src)
		return (size);
	while (index < size - 1 && src[index])
	{
		str[index] = src[index];
		++index;
	}
	str[index] = '\0';
	return (index);
}
