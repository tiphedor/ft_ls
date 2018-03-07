/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:56:20 by msteffen          #+#    #+#             */
/*   Updated: 2018/03/07 14:00:02 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"

int		ft_sort_name(void *ev1, void *ev2)
{
	t_entry *e1;
	t_entry *e2;

	e1 = (t_entry *)ev1;
	e2 = (t_entry *)ev2;
	return (strcmp(e2->name, e1->name));
}

void	ft_sort_result(t_list **lst_in, int (*cmp)(void*, void*), int reverse)
{
	t_list	*lst;
	t_list	*keep;
	t_entry	*e;

	lst = *lst_in;
	keep = lst;
	while (lst)
	{
		e = (t_entry *)lst->content;
		if (e->subentries)
		{
			ft_lstsort(&e->subentries, cmp);
			if (reverse)
				ft_lstrev(&e->subentries);
			ft_sort_result(&e->subentries, cmp, reverse);
		}
		lst = lst->next;
	}
}
