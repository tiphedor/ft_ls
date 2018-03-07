/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 14:35:22 by msteffen          #+#    #+#             */
/*   Updated: 2018/03/07 14:02:52 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENTRY_H
# define FT_ENTRY_H

# include "ft_ls_params.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "ft_entry.h"
# include <time.h>

# include <pwd.h>
# include <grp.h>
# include <sys/stat.h>
# include <errno.h>

typedef struct	s_entry
{
	char		type;

	int			o_r;
	int			o_w;
	int			o_x;
	int			g_r;
	int			g_w;
	int			g_x;
	int			w_r;
	int			w_w;
	int			w_x;

	int			nb_links;

	char		*user;
	char		*group;

	int			sz_bytes;
	int			sz_blocks;

	char		*last_edit_date;
	char		*name;
	char		*link_name;
	t_list		*subentries;

	int			s_isreg;
	int			s_isdir;
	int			s_islnk;

}				t_entry;

t_entry			*create_entry();
void			destroy_entry(t_entry **entry);
t_entry			*ft_parse_file_entry(char *fullpath, char *filename);

#endif
