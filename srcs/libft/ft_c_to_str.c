/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:38:38 by macbook           #+#    #+#             */
/*   Updated: 2020/03/14 21:01:58 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_c_to_str(char type)
{
	char	*str;

	if (!(str = (char*) malloc(sizeof(char) * 2)))
		return (NULL);
	ft_memset(str, 0, 2);	
	str[0] = type;
	return (str);
}
