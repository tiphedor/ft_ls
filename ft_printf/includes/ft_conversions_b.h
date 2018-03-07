/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions_b.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 12:26:55 by msteffen          #+#    #+#             */
/*   Updated: 2018/02/05 12:32:15 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERSIONS_B_H
# define FT_CONVERSIONS_B_H

# include "ft_flags.h"
# include "ft_buffer.h"
# include "ft_buffer_operations.h"
# include "ft_casts.h"
# include <stdarg.h>
# include <stdint.h>

int	ft_conversion_b(t_flags *flags, va_list *args, t_buffer *buffer);
int	ft_conversion_cb(t_flags *flags, va_list *args, t_buffer *buffer);

#endif
