/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions_x_tools.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 10:54:37 by msteffen          #+#    #+#             */
/*   Updated: 2018/02/05 16:33:39 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_conversions_x_tools.h"

int	ft_conversion_x_dash(t_buffer *buffer, t_flags *flags, int *params,
	uint64_t nb)
{
	char *nb_str;

	nb_str = ft_itoau64_base(nb, "0123456789abcdef");
	ft_buffer_putnchar(buffer, '0', params[0]);
	if (flags->hash && nb != 0)
	{
		ft_buffer_putstr(buffer, "0x");
		if (nb != 0 || flags->precision != 0)
			ft_buffer_putstr(buffer, nb_str);
		ft_buffer_putnchar(buffer, ' ', params[1] - 2);
	}
	else
	{
		if (nb != 0 || flags->precision != 0)
			ft_buffer_putstr(buffer, nb_str);
		ft_buffer_putnchar(buffer, ' ', params[1]);
	}
	free(nb_str);
	return (1);
}

int	ft_conversion_x_normpad(t_flags *flags, uint64_t nb, t_buffer *buffer,
	int *params)
{
	char *nb_str;

	nb_str = ft_itoau64_base(nb, "0123456789abcdef");
	ft_buffer_putnchar(buffer, '0', params[0]);
	if (nb != 0 || flags->precision != 0)
		ft_buffer_putstr(buffer, nb_str);
	free(nb_str);
	return (1);
}

int	ft_conversion_x_norm(t_buffer *buffer, t_flags *flags, int *params,
	uint64_t nb)
{
	char *nb_str;

	nb_str = ft_itoau64_base(nb, "0123456789abcdef");
	if (flags->hash && nb != 0)
	{
		if (flags->zero && flags->precision == -1)
		{
			ft_buffer_putstr(buffer, "0x");
			ft_buffer_putnchar(buffer, '0', params[1] - 2);
		}
		else
		{
			ft_buffer_putnchar(buffer, ' ', params[1] - 2);
			ft_buffer_putstr(buffer, "0x");
		}
	}
	else if (flags->precision == 0 && nb == 0)
		ft_buffer_putnchar(buffer, (flags->zero && flags->precision == -1)
			? '0' : ' ', params[1] + 1);
	else
		ft_buffer_putnchar(buffer, (flags->zero && flags->precision == -1)
			? '0' : ' ', params[1]);
	ft_conversion_x_normpad(flags, nb, buffer, params);
	free(nb_str);
	return (1);
}
