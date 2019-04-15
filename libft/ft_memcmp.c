/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <anas.elouargui@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 13:58:32 by aelouarg          #+#    #+#             */
/*   Updated: 2018/10/09 14:20:53 by aelouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*pt1;
	unsigned char	*pt2;
	size_t			i;
	int				c;

	i = 0;
	c = 0;
	pt1 = (unsigned char *)str1;
	pt2 = (unsigned char *)str2;
	while (i < n)
	{
		if (pt1[i] != pt2[i])
		{
			c = pt1[i] - pt2[i];
			return (c);
		}
		i++;
	}
	return (c);
}
