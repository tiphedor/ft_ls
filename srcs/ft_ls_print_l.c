/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_print_l.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:52:14 by msteffen          #+#    #+#             */
/*   Updated: 2018/03/07 14:01:23 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_print_l.h"

void	ft_print_list_l_permissions(t_entry *entry)
{
	ft_printf("%c", entry->o_r ? 'r' : '-');
	ft_printf("%c", entry->o_w ? 'w' : '-');
	ft_printf("%c", entry->o_x ? 'x' : '-');
	ft_printf("%c", entry->g_r ? 'r' : '-');
	ft_printf("%c", entry->g_w ? 'w' : '-');
	ft_printf("%c", entry->g_x ? 'x' : '-');
	ft_printf("%c", entry->w_r ? 'r' : '-');
	ft_printf("%c", entry->w_w ? 'w' : '-');
	ft_printf("%c", entry->w_x ? 'x' : '-');
}

void	ft_print_pad(int nb)
{
	int i;

	i = -1;
	while (++i <= nb)
		ft_printf(" ");
}

void	ft_calc_maxs(t_list *lst, t_maxs *maxs, int filter)
{
	t_entry *e;

	if (lst == NULL)
		return ;
	e = (t_entry *)lst->content;
	maxs->max_len_user = ft_strlen(e->user);
	maxs->max_len_group = ft_strlen(e->group);
	maxs->max_byte_len = ft_intlen(e->sz_bytes);
	maxs->max_link_len = ft_intlen(e->nb_links);
	maxs->total_blk_sz = e->sz_blocks;
	lst = lst->next;
	while (lst)
	{
		e = (t_entry *)lst->content;
		if ((int)ft_strlen(e->user) > maxs->max_len_user)
			maxs->max_len_user = ft_strlen(e->user);
		if ((int)ft_strlen(e->group) > maxs->max_len_group)
			maxs->max_len_group = ft_strlen(e->group);
		if (ft_intlen(e->nb_links) > maxs->max_link_len)
			maxs->max_link_len = ft_intlen(e->nb_links);
		if (ft_intlen(e->sz_bytes) > maxs->max_byte_len)
			maxs->max_byte_len = ft_intlen(e->sz_bytes);
		maxs->total_blk_sz += e->sz_blocks;
		lst = lst->next;
	}
	(void)filter;
}

void	ft_print_l_all(t_list *lst)
{
	t_entry	*entry;
	t_maxs	maxs;

	ft_calc_maxs(lst, &maxs, FILTER_ALL);
	ft_printf("total %d\n", maxs.total_blk_sz);
	while (lst)
	{
		entry = (t_entry *)lst->content;
		ft_printf("%c", entry->type);
		ft_print_list_l_permissions(entry);
		ft_print_pad(maxs.max_link_len - ft_intlen(entry->nb_links));
		ft_printf(" %d %s  %s", entry->nb_links, entry->user, entry->group);
		ft_print_pad(maxs.max_byte_len - ft_intlen(entry->sz_bytes));
		ft_printf(" %d %.12s %s", entry->sz_bytes, entry->last_edit_date, entry->name);
		if (entry->link_name != NULL)
			ft_printf(" -> %s\n", entry->link_name);
		else
			ft_printf("\n");
		lst = lst->next;
	}
}
