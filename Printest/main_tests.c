/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audumont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 01:38:33 by audumont          #+#    #+#             */
/*   Updated: 2019/11/17 16:36:23 by audumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_printf.h"

int main(void)
{
	/* Tests des flags */

	/*ft_printf("%0\n", "coucou");
	ft_printf("%.x\n", "coucou");
	ft_printf("%-x\n", "coucou");
	ft_printf("%x*\n", "coucou");
	*/

	printf("%-5d\n", 50);
	printf("%-10s\n", "coucou");

	printf("%0.5x\n", 50);
	printf("%0.*d\n", 4, 50);
	printf("%05d\n", 50);
	printf("%0*d\n", 5, 550);

	ft_printf_bis("%ll0d\n", 50);
}
