/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 18:35:49 by msteffen          #+#    #+#             */
/*   Updated: 2018/02/27 20:07:03 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include "ft_entry.h"

typedef struct	s_lslist
{
	t_entry **arr;
	int used_size;
	int allocated;
}				t_lslist;

t_lslist	*ft_list_init();
void		ft_list_destroy(t_lslist **lst);
void		ft_list_push(t_lslist *lst, t_entry *entry);
void		ft_list_sort_name(t_lslist *lst);


#endif
