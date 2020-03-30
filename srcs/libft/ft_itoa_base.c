/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:30:58 by macbook           #+#    #+#             */
/*   Updated: 2020/03/05 14:19:16 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


char	*ft_itoa_base(unsigned long int nb, char *base)
{
	size_t	len_nb;
	size_t	len_str;
	char	*tmp;
	int		index;

	index = 0;

	len_nb = ft_intlen_base(nb, base);
	len_str = ft_strlen(base);
	if (!(tmp = (char*) malloc(sizeof(char) * (len_nb + 1))))
		return (NULL);
	ft_bzero(tmp, len_nb + 1);
	while (nb >= len_str)
	{
		tmp[(int) len_nb - index - 1] = base[(nb % len_str)];
		nb = nb / len_str;
		++index;
	}
	tmp[(int)len_nb - index - 1] = base[(nb % (unsigned int) len_str)];
	return (tmp);
}
