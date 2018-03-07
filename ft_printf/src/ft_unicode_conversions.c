/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode_conversions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 19:03:35 by msteffen          #+#    #+#             */
/*   Updated: 2018/01/15 19:12:35 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_unicode_conversions.h"

int	print_bytes(unsigned char *bytes, int bytes_count, t_buffer *buffer)
{
	if (bytes_count == 4 && MB_CUR_MAX >= 4)
	{
		ft_buffer_putchar(buffer, bytes[3]);
		ft_buffer_putchar(buffer, bytes[2]);
		ft_buffer_putchar(buffer, bytes[1]);
		ft_buffer_putchar(buffer, bytes[0]);
		return (1);
	}
	if (bytes_count == 3 && MB_CUR_MAX >= 3)
	{
		ft_buffer_putchar(buffer, bytes[3]);
		ft_buffer_putchar(buffer, bytes[2]);
		ft_buffer_putchar(buffer, bytes[1]);
		return (1);
	}
	if (bytes_count == 2 && MB_CUR_MAX >= 2)
	{
		ft_buffer_putchar(buffer, bytes[3]);
		ft_buffer_putchar(buffer, bytes[2]);
		return (1);
	}
	return (-1);
}

int	ft_put_unicode_lowrange(unsigned long nb, t_buffer *buffer)
{
	unsigned char	utf_8[4];

	utf_8[3] = 0xC0 | ((nb >> 6) & 0x1F);
	utf_8[2] = 0x80 | (nb & 0x3F);
	return (print_bytes(utf_8, 2, buffer));
}

int	ft_put_unicode_midrange(unsigned long nb, t_buffer *buffer)
{
	unsigned char	utf_8[4];

	utf_8[3] = 0xE0 | ((nb >> 12) & 0x0F);
	utf_8[2] = 0x80 | ((nb >> 6) & 0x3F);
	utf_8[1] = 0x80 | (nb & 0x3F);
	return (print_bytes(utf_8, 3, buffer));
}

int	ft_put_unicode_highrange(unsigned long nb, t_buffer *buffer)
{
	unsigned char	utf_8[4];

	utf_8[0] = 0x80 | (nb & 0x3F);
	utf_8[1] = 0x80 | ((nb >> 6) & 0x3F);
	utf_8[2] = 0x80 | ((nb >> 12) & 0x3F);
	utf_8[3] = 0xF0 | ((nb >> 18) & 0x07);
	return (print_bytes(utf_8, 4, buffer));
}
