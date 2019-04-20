/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <anas.elouargui@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 14:52:05 by aelouarg          #+#    #+#             */
/*   Updated: 2018/10/11 16:07:56 by aelouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*pt;
	void		*tmp;

	if (!(pt = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	pt->next = NULL;
	if (content == NULL)
	{
		pt->content = NULL;
		pt->content_size = 0;
	}
	else
	{
		tmp = malloc(content_size);
		pt->content = ft_memcpy(tmp, content, content_size);
		pt->content_size = content_size;
	}
	return (pt);
}
