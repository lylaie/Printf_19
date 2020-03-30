#include "../../lib/ft_printf.h"

/*
** Changes the value of the minus flag.
*/

const char *ft_flag_minus(const char *format, t_t *t_save)
{
    t_save->t_flags.zero = 0;
    t_save->t_flags.minus =  1;
	return (++format);
}
