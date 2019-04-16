/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <anas.elouargui@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 06:39:33 by aelouarg          #+#    #+#             */
/*   Updated: 2018/10/09 15:33:23 by aelouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		i;
	int		len_src;

	i = 0;
	len_src = 0;
	while (src[len_src] != '\0')
		len_src++;
	if (!(dup = (char*)malloc(sizeof(*src) * (len_src + 1))))
		return (NULL);
	if (dup == 0)
		return (0);
	while (i < len_src)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
