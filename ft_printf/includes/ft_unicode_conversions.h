/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode_conversions.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 19:02:45 by msteffen          #+#    #+#             */
/*   Updated: 2018/02/05 10:22:56 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UNICODE_CONVERSIONS_H
# define FT_UNICODE_CONVERSIONS_H

# include "ft_buffer.h"
# include "ft_unicode_print.h"

int print_bytes(unsigned char *bytes, int bytes_count, t_buffer *buffer);
int ft_put_unicode_lowrange(unsigned long nb, t_buffer *buffer);
int ft_put_unicode_midrange(unsigned long nb, t_buffer *buffer);
int ft_put_unicode_highrange(unsigned long nb, t_buffer *buffer);

#endif
