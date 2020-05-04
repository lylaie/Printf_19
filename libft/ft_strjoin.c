/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:17:35 by macbook           #+#    #+#             */
/*   Updated: 2020/04/30 16:29:17 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dest;
	size_t	total;
	size_t	index;
	size_t	len_s1;

	if (!s1 || !s2)
		return (NULL);
	index = ft_strlen((char*)s2);
	len_s1 = ft_strlen((char*)s1);
	total = index + len_s1;
	if (!(dest = (char*)malloc(sizeof(char) * (total + 1))))
		return (NULL);
	index = 0;
	if (s1)
		while (*s1)
			dest[index++] = *(s1++);
	if (s2)
		while (*s2)
			dest[index++] = *(s2++);
	dest[index] = '\0';
	return (dest);
}
