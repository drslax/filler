/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <anas.elouargui@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 06:16:48 by aelouarg          #+#    #+#             */
/*   Updated: 2018/10/10 06:17:59 by aelouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	int		tmp_n;
	int		compt;

	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			ft_putchar(50);
			nb = 147483648;
		}
		else
			nb = -nb;
	}
	compt = 1;
	tmp_n = nb;
	while ((tmp_n /= 10) >= 1)
		compt *= 10;
	while (compt >= 1)
	{
		ft_putchar((nb / compt) + 48);
		nb %= compt;
		compt /= 10;
	}
}
