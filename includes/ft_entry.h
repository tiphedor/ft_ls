/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 14:35:22 by msteffen          #+#    #+#             */
/*   Updated: 2018/02/27 21:30:12 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENTRY_H
# define FT_ENTRY_H

# include "ft_ls_params.h"
# include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct	s_entry
{
	char 		type;

	int			o_r;
	int			o_w;
	int			o_x;
	int			g_r;
	int			g_w;
	int			g_x;
	int			w_r;
	int			w_w;
	int			w_x;

	int 		nb_links;

	char		*user;
	char		*group;

	int 		sz_bytes;
	int			sz_blocks;

	char		*last_edit_date;
	char		*name;
}				t_entry;

t_entry 	*create_entry();
void 		destroy_entry(t_entry **entry);
t_entry 	*create_entry_file(char *path);
void ft_print_entry(t_entry *entry, t_lsparams *params);

#endif
