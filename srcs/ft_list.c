/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 18:37:42 by msteffen          #+#    #+#             */
/*   Updated: 2018/02/27 20:10:33 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

#include <stdio.h>
t_lslist	*ft_list_init()
{
	t_lslist *lst;

	if ((lst = (t_lslist*)malloc(sizeof(t_lslist))) == NULL)
		return (NULL);
	if ((lst->arr = (t_entry**)malloc(sizeof(t_entry*) * 64)) == NULL)
		return (NULL);
	lst->allocated = 64;
	lst->used_size = 0;
	return (lst);
}

void		ft_list_destroy(t_lslist **lst)
{
	int i;
	t_entry *entry;

	i = 0;
	while (i < (*lst)->used_size)
	{
		entry = (*lst)->arr[i];
		destroy_entry(&entry);
		i++;
	}
	free((*lst)->arr);
	free(*lst);
	*lst = NULL;
}

static void	ft_list_realloc(t_lslist *lst)
{
	t_entry **tmp;

	tmp = (t_entry**)malloc(sizeof(t_entry*) * lst->allocated);
	ft_memcpy(tmp, lst->arr, sizeof(t_entry*) * lst->used_size);
	free(lst->arr);
	lst->arr = (t_entry**)malloc(sizeof(t_entry*) * (lst->allocated + 64));
	ft_memcpy(lst->arr, tmp, sizeof(t_entry*) * lst->used_size);
	free(tmp);
}

void		ft_list_push(t_lslist *lst, t_entry *entry)
{
	if (lst->used_size == lst->allocated - 2)
	{
		ft_list_realloc(lst);
		lst->allocated += 64;
	}
	lst->arr[lst->used_size] = entry;
	lst->used_size++;
}

void		ft_list_sort_name(t_lslist *lst)
{
	int i;
	t_entry *swap;

	i = 0;
	while (i < lst->used_size - 1)
	{
		if (ft_strcmp(lst->arr[i]->name, lst->arr[i + 1]->name) > 0)
		{
			swap = lst->arr[i];
			lst->arr[i] = lst->arr[i + 1];
			lst->arr[i + 1] = swap;
			i = -1;
		}
		i++;
	}
}
