/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions_diu.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:02:47 by msteffen          #+#    #+#             */
/*   Updated: 2018/02/05 10:22:33 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERSIONS_DIU_H
# define FT_CONVERSIONS_DIU_H

# include "ft_flags.h"
# include "ft_buffer_operations.h"
# include "ft_casts.h"
# include <stdarg.h>

int ft_conversion_d(t_flags *flags, va_list *args, t_buffer *buffer);
int ft_conversion_cd(t_flags *flags, va_list *args, t_buffer *buffer);
int ft_conversion_u(t_flags *flags, va_list *args, t_buffer *buffer);
int ft_conversion_cu(t_flags *flags, va_list *args, t_buffer *buffer);

#endif
