/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <anas.elouargui@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 22:16:22 by aelouarg          #+#    #+#             */
/*   Updated: 2018/10/09 22:20:11 by aelouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char*)src;
	str2 = (unsigned char*)dst;
	while (n > 0)
	{
		if (*str1 == (unsigned char)c)
		{
			*str2 = (unsigned char)c;
			str2++;
			return (str2);
		}
		*str2 = *str1;
		str1++;
		str2++;
		n--;
	}
	return (NULL);
}
