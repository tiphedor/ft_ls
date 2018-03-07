/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions_cs_pad.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:58:09 by msteffen          #+#    #+#             */
/*   Updated: 2018/02/05 10:21:57 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_conversions_cs_pad.h"

int	ft_conversion_cs_pad(int nb_spaces, t_flags *flags, wchar_t *c,
	t_buffer *buffer)
{
	if (flags->precision != -1)
		nb_spaces += ft_unicode_count_bytes(c) -
			ft_unicode_count_nbytes(c, flags->precision);
	if (!flags->dash)
		ft_buffer_putnchar(buffer, (flags->zero) ? '0' : ' ', nb_spaces);
	if (flags->precision != -1)
	{
		if (ft_putunicode_nstr(c, buffer, flags->precision) == -1)
			return (-1);
	}
	else
	{
		if (ft_putunicode_str(c, buffer) == -1)
			return (-1);
	}
	if (flags->dash)
		if (ft_buffer_putnchar(buffer, ' ', nb_spaces) == 0)
			return (-1);
	return (0);
}

int	ft_conversion_s_pad(char *c, t_buffer *buffer, t_flags *flags,
		int nb_spaces)
{
	if (flags->precision == -1 || flags->precision > (int)ft_strlen(c))
	{
		if (!flags->dash)
			ft_buffer_putnchar(buffer, (flags->zero) ? '0' : ' ', nb_spaces);
		ft_buffer_putstr(buffer, c);
		if (flags->dash)
			ft_buffer_putnchar(buffer, ' ', nb_spaces);
	}
	else
	{
		if (flags->width != 0)
			nb_spaces += ft_strlen(c) - flags->precision;
		if (!flags->dash)
			ft_buffer_putnchar(buffer, ' ', nb_spaces);
		ft_buffer_putnstr(buffer, c, flags->precision);
		if (flags->dash)
			ft_buffer_putnchar(buffer, ' ', nb_spaces);
	}
	return (1);
}
