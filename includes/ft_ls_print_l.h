/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_print_l.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:53:04 by msteffen          #+#    #+#             */
/*   Updated: 2018/03/07 14:03:39 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_PRINT_L_H
# define FT_LS_PRINT_L_H

# include "ft_entry.h"

# define FILTER_ALL 		1
# define FILTER_NON_NULL 	2
# define FILTER_NULL 		3

typedef struct	s_maxs
{
	int max_len_user;
	int max_len_group;
	int max_byte_len;
	int max_link_len;
	int total_blk_sz;
}				t_maxs;

void			ft_print_list_l_permissions(t_entry *entry);
void			ft_print_pad(int nb);
void			ft_calc_maxs(t_list *lst, t_maxs *maxs, int filter);
void			ft_print_l_all(t_list *lst);

#endif
