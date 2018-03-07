/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode_tools.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 19:04:07 by msteffen          #+#    #+#             */
/*   Updated: 2018/02/05 16:41:27 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UNICODE_TOOLS_H
# define FT_UNICODE_TOOLS_H

# include <wchar.h>

int ft_unicode_count_nbytes(wchar_t *str, int n);
int ft_unicode_count_bytes(wchar_t *str);
int ft_get_utf_len(unsigned long nb);

# ifndef FT_PRINTF_OUTOFRANGE
#  define FT_PRINTF_OUTOFRANGE -946
# endif

#endif
