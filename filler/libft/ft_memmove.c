/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <anas.elouargui@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 23:01:44 by aelouarg          #+#    #+#             */
/*   Updated: 2018/10/12 01:03:36 by aelouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*str;

	str = ft_memalloc(len);
	if (str == NULL)
		return (dst);
	ft_memcpy(str, src, len);
	ft_memcpy(dst, str, len);
	return (dst);
}
