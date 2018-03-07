/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions_cs_pad.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:58:24 by msteffen          #+#    #+#             */
/*   Updated: 2018/02/05 10:22:26 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERSIONS_CS_PAD_H
# define FT_CONVERSIONS_CS_PAD_H

# include <wchar.h>
# include "ft_flags.h"
# include "ft_unicode_tools.h"
# include "ft_unicode_print.h"
# include "ft_buffer.h"

int	ft_conversion_cs_pad(int nb_spaces, t_flags *flags, wchar_t *c,
	t_buffer *buffer);
int ft_conversion_s_pad(char *c, t_buffer *buffer, t_flags *flags,
		int nb_spaces);

#endif
