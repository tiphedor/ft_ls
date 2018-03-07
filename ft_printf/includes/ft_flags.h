/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:08:03 by msteffen          #+#    #+#             */
/*   Updated: 2018/02/05 10:22:48 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FLAGS_H
# define FT_FLAGS_H

# include "libft.h"

typedef struct	s_flags
{
	int		hash;
	int		zero;
	int		dash;
	int		plus;
	int		space;
	int		width;
	int		precision;
	int		j;
	int		z;
	int		hh;
	int		h;
	int		l;
	int		ll;
	char	*printf_buffer;
	int		percent_holder;
}				t_flags;

void			ft_init_flags(t_flags *flags);
int				ft_parse_flags(const char *str, t_flags *flags);

#endif
