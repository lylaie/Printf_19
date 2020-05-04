/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:10:10 by macbook           #+#    #+#             */
/*   Updated: 2020/05/04 21:06:02 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/ft_printf.h"
#include <strings.h>

static size_t	ft_printf2(char *str, int format)
{
	size_t	len;
	int		index;

	index = 0;
	len = ft_strlen(str);
	if (format == 1)
		ft_putstr(str);
	else if (format == 2)
	{
		while (str[index])
		{
			if (str[index] == -1)
			{
				write(1, 0, 1);
				break ;
			}
			write(1, &str[index], 1);
			index++;
		}
		len = index;
	}
	return (len);
}

int				ft_printf(const char *format, ...)
{
	va_list lst;
	t_t		t_s;
	char	*tmp_c;
	size_t	l;

	va_start(lst, format);
	ft_init(&(t_s.t_final));
	while (*format && (t_s.t_final.okay == 1))
	{
		ft_reinit(&t_s);
		if (*format == '%')
			format = ft_parser(lst, format, &t_s);
		else
		{
			tmp_c = ft_c_to_str(*format);
			t_s.t_final.f_str = ft_free_double_string(\
			ft_strjoin(t_s.t_final.f_str, tmp_c), t_s.t_final.f_str, tmp_c);
			++format;
		}
	}
	l = t_s.t_final.okay ? ft_printf2(t_s.t_final.f_str, t_s.t_final.okay) : -1;
	free(t_s.t_final.f_str);
	va_end(lst);
	return (l);
}
