/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <anas.elouargui@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 16:43:08 by aelouarg          #+#    #+#             */
/*   Updated: 2018/10/11 22:35:31 by aelouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*begin_lst;
	t_list	*ftmp;

	if (!lst || !f)
		return (NULL);
	if (!(new_lst = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	begin_lst = new_lst;
	while (lst)
	{
		if (lst->next)
			new_lst->next = (t_list*)malloc(sizeof(t_list));
		else
			new_lst->next = NULL;
		ftmp = (*f)(lst);
		new_lst->content = malloc(ftmp->content_size);
		ft_memcpy(new_lst->content, ftmp->content, ftmp->content_size);
		new_lst->content_size = ftmp->content_size;
		new_lst = new_lst->next;
		lst = lst->next;
	}
	return (begin_lst);
}
