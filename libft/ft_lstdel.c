/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <anas.elouargui@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 16:07:59 by aelouarg          #+#    #+#             */
/*   Updated: 2018/10/11 16:18:06 by aelouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*pt;

	if (alst && del)
	{
		while (*alst != NULL)
		{
			pt = *alst;
			del((*alst)->content, (*alst)->content_size);
			*alst = (*alst)->next;
			free(pt);
		}
	}
}
