/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audumont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:20:12 by audumont          #+#    #+#             */
/*   Updated: 2020/03/05 13:52:27 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	index;

	index = ft_strlen((char*)s1);
	if (!(copy = (char*)malloc(sizeof(char) * (index + 1))))
		return (NULL);
	index = 0;
	while (s1[index])
	{
		copy[index] = s1[index];
		index++;
	}
	copy[index] = '\0';
	return (copy);
}
