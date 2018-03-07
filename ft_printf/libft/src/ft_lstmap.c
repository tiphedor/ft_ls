/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:12:20 by msteffen          #+#    #+#             */
/*   Updated: 2017/11/10 16:19:17 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_lst;
	t_list *begin;
	t_list *tmp;

	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	new_lst = ft_lstnew(tmp->content, tmp->content_size);
	begin = new_lst;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		new_lst->next = ft_lstnew(tmp->content, tmp->content_size);
		new_lst = new_lst->next;
		lst = lst->next;
	}
	return (begin);
}
