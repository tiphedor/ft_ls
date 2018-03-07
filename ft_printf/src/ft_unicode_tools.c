/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 19:05:11 by msteffen          #+#    #+#             */
/*   Updated: 2018/02/05 16:37:43 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_unicode_tools.h"

int	ft_unicode_count_nbytes(wchar_t *str, int n)
{
	int i;
	int len;
	int full;

	i = 0;
	len = 0;
	full = 0;
	while (str[i] && !full)
	{
		if (len + ft_get_utf_len(str[i]) > n)
			full = 1;
		else
			len += ft_get_utf_len(str[i]);
		i++;
	}
	return (len);
}

int	ft_unicode_count_bytes(wchar_t *str)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[i])
	{
		len += ft_get_utf_len(str[i]);
		i++;
	}
	return (len);
}

int	ft_get_utf_len(unsigned long nb)
{
	if (nb >= 0xd800 && nb <= 0xDFFF)
		return (-1);
	if (nb <= 0x7F)
		return (1);
	else if (nb <= 0x7FF)
		return (2);
	else if (nb <= 0xFFFF)
		return (3);
	else if (nb <= 0x10FFFF)
		return (4);
	return (-1);
}
