/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode_print.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:05:42 by msteffen          #+#    #+#             */
/*   Updated: 2018/02/05 10:22:59 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UNICODE_PRINT_H
# define FT_UNICODE_PRINT_H

# include "ft_buffer_operations.h"
# include "ft_unicode_conversions.h"
# include "ft_unicode_tools.h"
# include <wchar.h>

int ft_putunicode_char(unsigned long nb, t_buffer *buffer);
int ft_putunicode_str(wchar_t *str, t_buffer *buffer);
int ft_putunicode_nstr(wchar_t *str, t_buffer *buffer, int n);

#endif
