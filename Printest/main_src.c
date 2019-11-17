#include "../lib_printf.h"

int main(int argc, char **argv)
{
	// TESTS DES FONCTIONS PUTNBR, PUTCHAR, PUTSTR //
	
	ft_putnbr(45);
	ft_putchar('\n');
	ft_putstr("coucou");
	ft_putchar('\n');
	ft_putnbr(0xaef);
	printf("%d\n", 0xaef);

	//printf("%d\n", aef);
	
	printf("%-005d",50);
}
