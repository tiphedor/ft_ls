/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 13:57:41 by msteffen          #+#    #+#             */
/*   Updated: 2018/02/05 15:49:24 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_conversions.h"
# include "ft_buffer.h"
# include "ft_flags.h"
# include "ft_styling.h"

int	ft_printf(const char *format, ...);
int ft_printf_fd(int fd, const char *format, ...);
int	ft_printf_tofd(const char *format, int fd, va_list *args);

#endif
