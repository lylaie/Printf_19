/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audumont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 01:38:33 by audumont          #+#    #+#             */
/*   Updated: 2019/11/16 01:50:23 by audumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_printf.h"

int main(void)
{
	/* Tests des flags */

	ft_printf("%0\n", "coucou");
	ft_printf("%.x\n", "coucou");
	ft_printf("%-x\n", "coucou");
	//ft_printf("%x*\n", "coucou");
}
