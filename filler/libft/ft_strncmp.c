/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <anas.elouargui@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 21:25:17 by aelouarg          #+#    #+#             */
/*   Updated: 2018/10/09 15:36:07 by aelouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	int				c;
	unsigned char	*st1;
	unsigned char	*st2;

	i = 0;
	c = 0;
	st1 = (unsigned char *)str1;
	st2 = (unsigned char *)str2;
	while ((st1[i] || st2[i]) && c == 0 && i < n)
	{
		c = st1[i] - st2[i];
		i++;
	}
	return (c);
}
