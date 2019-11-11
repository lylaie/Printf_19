/*# **************************************************************************** #*/
/*#                                                                              #*/
/*#                                                         :::      ::::::::    #*/
/*#    Makefile                                           :+:      :+:    :+:    #*/
/*#                                                     +:+ +:+         +:+      #*/
/*#    By: audumont <marvin@42.fr>                    +#+  +:+       +#+         #*/
/*#                                                 +#+#+#+#+#+   +#+            #*/
/*#    Created: 2019/10/10 15:13:55 by audumont          #+#    #+#              #*/
/*   Updated: 2019/11/10 14:35:12 by audumont         ###   ########.fr       */
/*#                                                                              #*/
/*# **************************************************************************** #*/

#ifndef LIB_PRINTF_H
# define LIB_PRINTF_H

# define STRING_ARRAY "string", "digit", "character", "hexa", "pourcent"
# define FORMAT_CHAR "sdcxp"
# define BASE_16 "0123456789abcdef"
# define BASE_10 "0123456789"

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putstr(char *str);
int	ft_putchar(char c);
long long int	ft_convert(long long int nbr, int base, char *tank);
int	ft_putnbr(long long int nb);
int		ft_printf(const char *str, ...);
char	**ft_split(const char *str, char c);
char	ft_type_of(const char *str);
int	ft_print_format(char type, va_list lst);

#endif
