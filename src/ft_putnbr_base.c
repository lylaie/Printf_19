/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audumont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 18:38:31 by audumont          #+#    #+#             */
/*   Updated: 2019/08/21 19:46:31 by audumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_check_base(char *str)
{
	int	index;
	int	index2;

	index = 0;
	while (str[index] != '\0')
	{
		index2 = index + 1;
		if (str[index] < 32 || str[index] == '-' || str[index] == '+')
			return (1);
		while (str[index2] != '\0')
		{
			if (str[index] == str[index2])
				return (1);
			index2++;
		}
		index++;
	}
	if (index <= 1)
		return (1);
	return (0);
}

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_show_result(int nb, char *base, int len_nb)
{
	char	dest[len_nb + 1];
	int		div;
	int		len_str;
	int		index;

	len_str = ft_strlen(base);
	div = nb;
	index = len_nb;
	while (index >= 0)
	{
		dest[index] = base[div % len_str];
		ft_putchar(dest[index]);
		if (div < len_str)
			break ;
		div = div / len_str;
		index--;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	nb;
	long int	nb1;
	int			len_nb;

	len_nb = 0;
	if (!(ft_check_base(base)))
	{
		nb = nbr;
		if (nbr < 0)
		{
			ft_putchar('-');
			nb = -nbr;
		}
		nb1 = nb;
		while (nb > 10)
		{
			nb = nb / 10;
			len_nb++;
		}
		len_nb++;
		ft_show_result(nb1, base, len_nb);
	}
}
