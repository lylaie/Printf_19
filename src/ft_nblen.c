#include "../lib_printf.h"

int	ft_nblen(long long int nb, int base)
{
	int len;
	long long int nbr;

	len = 0;
	nbr = nb & ((~0) >> 1);
	while (nbr >= base)
	{
		nbr = nbr / base;
		len++;
	}
	len++;
	return (len);

	 
}
