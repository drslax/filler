/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <anas.elouargui@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 13:27:20 by aelouarg          #+#    #+#             */
/*   Updated: 2018/10/09 15:30:06 by aelouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	ch;
	unsigned char	*pt;

	i = 0;
	ch = (unsigned char)c;
	pt = (unsigned char *)str;
	while (i < n)
	{
		if (ch == pt[i])
			return ((void *)pt + i);
		i++;
	}
	return (NULL);
}
