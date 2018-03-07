/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:05:59 by msteffen          #+#    #+#             */
/*   Updated: 2018/02/07 11:58:22 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_unicode_print.h"

int	ft_putunicode_char(unsigned long nb, t_buffer *buffer)
{
	if (nb >= 0xd800 && nb <= 0xDFFF)
		return (-1);
	if (nb <= 0x7F)
		return (ft_buffer_putchar(buffer, nb));
	else if (nb <= 255 && MB_CUR_MAX == 1)
		return (ft_buffer_putchar(buffer, nb));
	else if (nb <= 0x7FF)
		return (ft_put_unicode_lowrange(nb, buffer));
	else if (nb <= 0xFFFF)
		return (ft_put_unicode_midrange(nb, buffer));
	else if (nb <= 0x10FFFF)
		return (ft_put_unicode_highrange(nb, buffer));
	return (-1);
}

int	ft_putunicode_str(wchar_t *str, t_buffer *buffer)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_putunicode_char(str[i], buffer) == -1)
			return (-1);
		i++;
	}
	return (1);
}

int	ft_putunicode_nstr(wchar_t *str, t_buffer *buffer, int n)
{
	int i;
	int char_count;

	i = 0;
	char_count = 0;
	while (str[i] && char_count + ft_get_utf_len(str[i]) <= n)
	{
		char_count += ft_get_utf_len(str[i]);
		if (ft_putunicode_char(str[i], buffer) == -1)
			return (-1);
		i++;
	}
	return (1);
}
