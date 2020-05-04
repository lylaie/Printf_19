/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:33:35 by macbook           #+#    #+#             */
/*   Updated: 2020/04/30 15:57:13 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int index;
	int	diff;

	index = 0;
	while (s1[index] || s2[index])
	{
		diff = s1[index] - s2[index];
		if (diff)
			return (diff);
		++index;
	}
	return (0);
}
