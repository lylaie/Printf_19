/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_lib.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audumont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:35:40 by audumont          #+#    #+#             */
/*   Updated: 2019/11/21 18:44:23 by audumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_LIB_H
# define PRINTF_LIB_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef	struct		s_flags
{
	int				minus;
	int				zero;
	int				point;
	int				sharp;
	int				plus;
	int				l;
	int				ll;
	int				h;
	int				hh;
	int				star;
	int				quote;
}					t_flags;

# define FORMAT_VALIDE "-0.*lh'#sdxiuXo"
# define FORMAT_FLAGS "-0.*lh'#"
# define FORMAT_CHAR "sdxiuXo-0"
# define FORMAT_S_FLAGS "minus", "zero", "point", "star", "l", "ll", "h","hh", "quote", "sharp"

void				ft_initialize_flags(t_flags flags);
char				ft_type_of(const char *format, t_flags flags, va_list lst);
int				ft_type_of_flags(const char *format, t_flags flags, char type, va_list lst);
int					ft_printf(const char *format, ...);
void				ft_putchar(char c);

#endif
