/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_casts.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:07:30 by msteffen          #+#    #+#             */
/*   Updated: 2018/02/05 10:22:19 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CASTS_H
# define FT_CASTS_H

# include <stdarg.h>
# include <stdint.h>
# include "ft_flags.h"

int64_t		ft_cast_signed(t_flags *flags, va_list *args);
uint64_t	ft_cast_unsigned(t_flags *flags, va_list *args);
#endif
