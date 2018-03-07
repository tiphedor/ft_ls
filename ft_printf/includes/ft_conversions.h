/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:05:14 by msteffen          #+#    #+#             */
/*   Updated: 2018/02/05 12:27:25 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERSIONS_H
# define FT_CONVERSIONS_H

# include "ft_flags.h"
# include "ft_buffer.h"
# include "ft_conversions_diu.h"
# include "ft_conversions_p.h"
# include "ft_conversions_ox.h"
# include "ft_conversions_cs.h"
# include "ft_conversions_b.h"
# include <stdarg.h>

void ft_init_conversions(int (*conversions[256])(t_flags *, va_list *,
	t_buffer *));

#endif
