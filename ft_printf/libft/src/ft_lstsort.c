/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:42:47 by msteffen          #+#    #+#             */
/*   Updated: 2018/03/07 13:43:29 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_sort_linked_list_insert(t_list **head, t_list *new_node,
	int (*cmp)(void*, void*))
{
	t_list *tmp;

	if (*head == NULL || cmp(new_node->content, (*head)->content) < 0)
	{
		new_node->next = *head;
		*head = new_node;
		return ;
	}
	tmp = *head;
	while (tmp->next && cmp(new_node->content, tmp->next->content) > 0)
		tmp = tmp->next;
	new_node->next = tmp->next;
	tmp->next = new_node;
}

void		ft_lstsort(t_list **head, int (*cmp)(void*, void*))
{
	t_list	*new_head;
	t_list	*tmp;
	t_list	*tmp1;

	tmp = *head;
	tmp1 = NULL;
	new_head = NULL;
	while (tmp)
	{
		tmp1 = tmp;
		tmp = tmp->next;
		ft_sort_linked_list_insert(&new_head, tmp1, cmp);
	}
	*head = new_head;
}
