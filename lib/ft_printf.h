/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audumont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:42:11 by audumont          #+#    #+#             */
/*   Updated: 2020/05/04 22:05:40 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

/*
 ** CONSTANTES
*/

# define FLAGS "*0.-"
# define CONVERSION "cspdiuxX%"
# define BASE_10 "0123456789"
# define BASE_16 "0123456789abcdef"
# define BASE_16_X "0123456789ABCDEF"

/*
 ** STRUCTURES
*/

typedef	struct	s_f
{
	char	*f_str;
	int		len;
	int		okay;
}				t_f;

typedef struct	s_flag
{
	int		zero;
	int		minus;
	int		star;
	int		dot;
}				t_flag;

typedef	struct	s_t
{
	t_flag	t_flags;
	int		width;
	int		precision;
	t_f		t_final;
}				t_t;

/*
** PROTOTYPES
*/

/*
 ** INITIALISATION
*/

const char		*ft_parser(va_list lst, const char *format, t_t *t_save);
int				ft_printf(const char *format, ...);
void			ft_init(t_f	*t_final);
void			ft_reinit(t_t *t_all);
const char		*ft_width_flag(const char *format, t_t *t_save);
int				ft_is_conver(char type);
int				ft_is_flag(char type);
int				ft_is_format(char type);

/*
 ** FLAGS
*/

const char		*ft_t_of_flag(char t, const char *fmt, va_list lst, t_t *t_s);
const char		*ft_flag_dot(const char *format, t_t *t_save, va_list lst);
const char		*ft_flag_star(const char *format, va_list lst, t_t *t_save);
const char		*ft_flag_minus(const char *format, t_t *t_save);
const char		*ft_flag_zero(const char *format, t_t *t_save);
const char		*ft_width_flag(const char *format, t_t *t_save);

/*
 ** CONVERSIONS
*/

const char		*ft_type_conv(char t, const char *fmt, va_list lst, t_t *t_s);
char			*ft_init_str(t_t *t_save);
char			*ft_init_str_i(t_t *t_save);
char			*ft_init_str_p(t_t *t_save);
char			*ft_conv_c(char *str, va_list lst, t_t *t_save);
char			*ft_conv_i(char *str, va_list lst, t_t *t_save);
char			*ft_conv_x(char *str, va_list lst, t_t *t_save, char type);
char			*ft_conv_s(char *str, va_list lst, t_t *t_save);
char			*ft_conv_u(char *str, va_list lst, t_t *t_save);
char			*ft_conv_p(char *str, va_list lst, t_t *t_save);
char			*ft_conv_pou(char *str, t_t *t_save);
char			*ft_conv_no_min_wid(char *str, char *tmp, t_t *t_sa, size_t qq);
char			*ft_conv_no_minus(char *str, char *tmp, t_t *t_ss, size_t lstr);

/*
 ** SHOWS
*/

char			*ft_show_i(long long int nb, char *snb, char *str, t_t *t_save);
size_t			ft_show_i_2(size_t slen, char **str, t_t *t_save, size_t lnb);
char			*ft_show_i_5(char *snb, char *str, t_t *t_save, size_t lnb);
char			*ft_show_u(char *str_nb, char *str, t_t *t_save);

/*
 ** CLEANING FUNCTIONS
*/

void			ft_free_tt(t_t *t_save);
char			*ft_free_string(char *str_re, char *str_f);
char			*ft_free_double_string(char *str_re, char *str_f1, char *sf2);
int				ft_free_struct(t_t *t_save);
#endif
