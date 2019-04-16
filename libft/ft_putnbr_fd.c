/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <anas.elouargui@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 06:27:18 by aelouarg          #+#    #+#             */
/*   Updated: 2018/10/10 06:30:55 by aelouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	int		tmp_n;
	int		compt;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		if (nb == -2147483648)
		{
			ft_putchar_fd(50, fd);
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
		ft_putchar_fd((nb / compt) + 48, fd);
		nb %= compt;
		compt /= 10;
	}
}
