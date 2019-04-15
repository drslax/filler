/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <anas.elouargui@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 01:02:29 by aelouarg          #+#    #+#             */
/*   Updated: 2018/10/10 04:32:26 by aelouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*pt;

	i = start;
	if (!s)
		return (NULL);
	if (!(pt = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[i] && i - start < len)
	{
		pt[i - start] = s[i];
		i++;
	}
	pt[i - start] = '\0';
	return (pt);
}
