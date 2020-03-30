#include "../../lib/ft_printf.h"

/*
** Changes the value of the precision or the width in function of the position of the star flag.
** If the width already exists or if dot flag exists, the flag star is corresponding to the precision. 
*/

const char 	*ft_flag_star(const char *format, va_list lst, t_t *t_save)
{
    if ((t_save->t_flags.dot && !t_save->width) || t_save->width)
    {
        t_save->precision = va_arg(lst, int);
		t_save->t_flags.minus = t_save->precision < 0 ? 1 : t_save->t_flags.minus;
		t_save->t_flags.zero = t_save->precision < 0 ? t_save->t_flags.zero-- : t_save->t_flags.zero;
        t_save->precision = t_save->precision > 0 ? t_save->precision : 0;
    }
    else
    {
        t_save->width = va_arg(lst, int);
        t_save->t_flags.minus = t_save->width < 0 ? 1 : t_save->t_flags.minus;
		t_save->t_flags.zero = t_save->width < 0 ? 0 : t_save->t_flags.zero;
        t_save->width = t_save->width > 0 ? t_save->width : -t_save->width;
    }
	t_save->t_flags.star++;
	return (++format);
}
