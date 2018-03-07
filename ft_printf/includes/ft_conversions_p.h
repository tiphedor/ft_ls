/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions_p.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:43:36 by msteffen          #+#    #+#             */
/*   Updated: 2018/02/05 10:22:40 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERSIONS_P_H
# define FT_CONVERSIONS_P_H

# include <stdarg.h>
# include "ft_buffer_operations.h"
# include "ft_casts.h"

int ft_conversion_p(t_flags *flags, va_list *args, t_buffer *buffer);

#endif
