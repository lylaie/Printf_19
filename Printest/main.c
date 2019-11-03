#include "../lib_printf.h"

int main(void)
{
	ft_printf("%s%d%c%a", "coucou", 9, '\n');
//	printf("coucou%Q", "string");
	ft_printf("coucou %s,%d blablabl: %c","mon lapin", 42, 'Z');
}
