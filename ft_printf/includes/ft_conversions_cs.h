/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions_cs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:25:56 by msteffen          #+#    #+#             */
/*   Updated: 2018/02/05 10:22:30 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERSIONS_CS_H
# define FT_CONVERSIONS_CS_H

# include "ft_flags.h"
# include "ft_buffer.h"
# include "ft_casts.h"
# include "ft_conversions_cs_pad.h"
# include "ft_unicode_print.h"
# include <stdarg.h>

int ft_conversion_c(t_flags *flags, va_list *args, t_buffer *buffer);
int ft_conversion_s(t_flags *flags, va_list *args, t_buffer *buffer);
int ft_conversion_cc(t_flags *flags, va_list *args, t_buffer *buffer);
int ft_conversion_cs(t_flags *flags, va_list *args, t_buffer *buffer);

#endif
