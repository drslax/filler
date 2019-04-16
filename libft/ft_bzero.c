/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <anas.elouargui@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 21:50:11 by aelouarg          #+#    #+#             */
/*   Updated: 2018/10/09 15:28:13 by aelouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*pt;
	int				c;

	c = 0;
	pt = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		pt[i] = (unsigned char)c;
		i++;
	}
	s = (void *)pt;
}
