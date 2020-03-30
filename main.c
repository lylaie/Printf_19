#include "lib/ft_printf.h"

int main()
{
/*	printf("p %--8.11i\n", -1404374253);
	ft_printf("f %--8.11i\n", -1404374253);	

	printf("p %---6.11d\n", -1966786058);	
	ft_printf("f %---6.11d\n", -1966786058);	

	printf("p %-*.10d\n", 2, -188379443);	
	ft_printf("f %-*.10d\n", 2, -188379443);	

	printf("p %-*.11d\n", -5, -1470975852);
	ft_printf("f %-*.11d\n", -5, -1470975852);	

	printf("p %004.10i\n", -665205373);
	ft_printf("f %004.10i\n", -665205373);

*/

	printf("p %68c%-43c%-123c\n", -1, -40, 0);
	ft_printf("f %68c%-43c%-123c\n", -1, -40, 0);
	return (0);	
}
