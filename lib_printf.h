/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_printf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audumont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:51:59 by audumont          #+#    #+#             */
/*   Updated: 2019/11/15 20:28:34 by audumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PRINTF_H
# define LIB_PRINTF_H

# define STRING_ARRAY "str", "dig", "char", "hexa", "%", "int","unint", "hexa U"
# define FORMAT_CHAR "sdcxpiuXo"
# define FORMAT_FLAGS "-0.*"
# define BASE_8 "012345678"
# define BASE_16 "0123456789abcdef"
# define BASE_16_U "0123456789ABCDEF"
# define BASE_10 "0123456789"
# define UNIT_MAX 429496765535
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

void		ft_putstr(char *str);
int			ft_putchar(char c);
void		ft_convert(long long int nbr, int base, char *tank);
int			ft_putnbr(long long int nb);
int			ft_printf(const char *str, ...);
char		**ft_split(const char *str, char c);
char		ft_type_of(const char *str);
int			ft_print_format(char type, va_list lst);
int			ft_nblen(long long int nb, int base);
int			ft_strlen(char *str);
int			ft_check_format(char type, va_list lst);

#endif
