/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:10:10 by macbook           #+#    #+#             */
/*   Updated: 2020/03/27 17:48:48 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/ft_printf.h"
#include <strings.h>

static size_t	ft_printf_part_two(char *str, int format)
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
					break;
				}
				write(1, &str[index], 1);
				index++;
			}
			len = index;
		}
		return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list lst;
	t_t		t_save;
	char	*tmp_c;
	size_t	len;
	char 	*tmp_s;
	
	va_start(lst, format);
	ft_init(&(t_save.t_final));
	while (*format && (t_save.t_final.okay == 1))
	{
		ft_reinit(&t_save);
		if (*format == '%')
			format = ft_parser(lst, format, &t_save);
		else
		{				
			tmp_c = ft_c_to_str(*format);
			tmp_s = t_save.t_final.f_str;
			//free(t_save.t_final.f_str);
			t_save.t_final.f_str = ft_strjoin(tmp_s, tmp_c);
			free(tmp_c);
			free(tmp_s);
			++format;
		}
	}
	len = t_save.t_final.okay ? ft_printf_part_two(t_save.t_final.f_str, t_save.t_final.okay) : -1;
	free(t_save.t_final.f_str);
	va_end(lst);
	return (len);
}
