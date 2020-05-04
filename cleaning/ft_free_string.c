/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:19:24 by macbook           #+#    #+#             */
/*   Updated: 2020/05/04 22:16:20 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf.h"

char	*ft_free_string(char *str_re, char *str_f)
{
	free(str_f);
	return (str_re);
}

char	*ft_free_double_string(char *str_re, char *str_f1, char *str_f2)
{
	free(str_f1);
	free(str_f2);
	return (str_re);
}
