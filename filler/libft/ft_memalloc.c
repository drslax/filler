/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <anas.elouargui@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 15:50:13 by aelouarg          #+#    #+#             */
/*   Updated: 2018/10/09 15:59:51 by aelouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*ret;

	ret = (void*)malloc(sizeof(size_t) * size);
	if (!ret)
		return (NULL);
	ft_bzero(ret, size);
	return (ret);
}
