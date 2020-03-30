#include "../../lib/ft_printf.h"

 const char     *ft_width_flag(const char *format, t_t *t_save)
 {
    if (!t_save->width || (t_save->width && t_save->t_flags.star && !t_save->t_flags.dot))
    {
		t_save->width = 0;
        while (*format >= '0' && *format <= '9')
        {
            t_save->width = t_save->width * 10 + (*format - '0');
            ++format;
        }
    }
    else
    {
        while (*format >= '0' && *format <= '9')
        {
            t_save->precision = t_save->precision * 10 + (*format - '0');
            ++format;
        }
    }
    return (format);
 }
