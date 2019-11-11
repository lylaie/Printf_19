#include "../lib_printf.h"

int main(void)
{
	/*ft_printf("%s%d%c%a", "coucou", 9, '\n');
	printf("coucou%Q", "string");
	ft_printf("coucou %s,%d blablabl: %c","mon lapin", 42, 'Z');*/


	//TESTS DE L AFFICHAGE DES ENTIERS//
	//printf("premier nombre : %d", 155);
	//printf("deuxième nombre : %x", 155);
	//ft_printf("deuxième nombre : %x", 155);
	//
	

	/*TESTS DE L AFFICHAGE DES P
	char *dest;
	dest = "coucou";
	printf("affichage en hexa de l'adresse : %p\n", &dest);
	ft_printf("affichage en hexa de l'adresse : %p\n", &dest);
	*/

	/* TESTS DE L AFFICHAGE DES I 
	printf("affichage des i :%i\n", );*/

	/* TEST DE L AFFICHAGE DES ENTIERS */
	char *dest;
	dest = "coucou";

	printf("test de conversion : %i\n", printf("%p\n", &dest));
	printf("test de conversion : %i\n", ft_printf("%p\n", &dest));
}
