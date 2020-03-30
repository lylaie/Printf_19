#include "../../lib/ft_printf.h"

const char  *ft_flag_dot(const char *format, t_t *t_save, va_list lst)
{	
    ++format;
	++t_save->t_flags.dot;
    if (!t_save->precision)
    {
		t_save->precision = 0;
		if (*format == '*')
		{
				t_save->precision = va_arg(lst, int);
				t_save->t_flags.dot = t_save->precision < 0 ? 0 : 1;
				t_save->precision = t_save->precision > 0 ? t_save->precision : 0;
				//t_save->t_flags.zero = (!t_save->precision && t_save->t_flags.zero == 1) ? 0 : t_save->t_flags.zero--;
				++format;
				return (format);
		}
		else
		{
			while (*format >= '0' && *format <= '9')
			{
			   t_save->precision = t_save->precision * 10 + (*format - '0');
			   ++format;
			}
	}
		t_save->t_flags.zero = (t_save->t_flags.zero == 1  && !t_save->precision ? -1 : t_save->t_flags.zero);
    }
    return (format);
}
