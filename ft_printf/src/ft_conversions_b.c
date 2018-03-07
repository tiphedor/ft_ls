/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 12:25:57 by msteffen          #+#    #+#             */
/*   Updated: 2018/02/05 12:33:54 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_conversions_b.h"

int	ft_conversion_b_pad(t_flags *flags, t_buffer *buffer, int *params,
	uint64_t nb)
{
	char *nb_str;

	nb_str = ft_itoau64_base(nb, "01");
	if (!flags->dash)
		ft_buffer_putnchar(buffer, ' ', params[1]);
	if ((flags->hash && nb != 0)
		|| (nb == 0 && flags->precision == 0 && flags->hash))
		ft_buffer_putstr(buffer, "0b");
	ft_buffer_putnchar(buffer, '0', params[0]);
	if (flags->precision != 0 || nb != 0)
		ft_buffer_putstr(buffer, nb_str);
	if (flags->width != 0 && nb == 0 && flags->precision == 0)
		ft_buffer_putchar(buffer, ' ');
	if (flags->dash)
		ft_buffer_putnchar(buffer, ' ', params[1]);
	free(nb_str);
	return (1);
}

int	ft_conversion_b(t_flags *flags, va_list *args, t_buffer *buffer)
{
	uint64_t	nb;
	char		*nb_str;
	int			params[2];

	nb = ft_cast_unsigned(flags, args);
	nb_str = ft_itoau64_base(nb, "01");
	params[0] = flags->precision - ft_strlen(nb_str)
		- 2 * (flags->hash && nb != 0);
	params[1] = flags->width - ft_strlen(nb_str)
		- 2 * (flags->hash && nb != 0);
	if (params[0] > 0)
		params[1] -= params[0];
	params[0] = (params[0] < 0) ? 0 : params[0];
	if (!flags->dash && flags->zero && flags->precision == -1)
	{
		params[0] += params[1];
		params[1] = 0;
	}
	ft_conversion_b_pad(flags, buffer, params, nb);
	free(nb_str);
	return (1);
}

int	ft_conversion_cb_pad(t_flags *flags, t_buffer *buffer, int *params,
	uint64_t nb)
{
	char *nb_str;

	nb_str = ft_itoau64_base(nb, "01");
	if (!flags->dash)
		ft_buffer_putnchar(buffer, ' ', params[1]);
	if ((flags->hash && nb != 0)
		|| (nb == 0 && flags->precision == 0 && flags->hash))
		ft_buffer_putstr(buffer, "0B");
	ft_buffer_putnchar(buffer, '0', params[0]);
	if (flags->precision != 0 || nb != 0)
		ft_buffer_putstr(buffer, nb_str);
	if (flags->width != 0 && nb == 0 && flags->precision == 0)
		ft_buffer_putchar(buffer, ' ');
	if (flags->dash)
		ft_buffer_putnchar(buffer, ' ', params[1]);
	free(nb_str);
	return (1);
}

int	ft_conversion_cb(t_flags *flags, va_list *args, t_buffer *buffer)
{
	uint64_t	nb;
	char		*nb_str;
	int			params[2];

	nb = ft_cast_unsigned(flags, args);
	nb_str = ft_itoau64_base(nb, "01");
	params[0] = flags->precision - ft_strlen(nb_str) -
		2 * (flags->hash && nb != 0);
	params[1] = flags->width - ft_strlen(nb_str) -
		2 * (flags->hash && nb != 0);
	if (params[0] > 0)
		params[1] -= params[0];
	params[0] = (params[0] < 0) ? 0 : params[0];
	if (!flags->dash && flags->zero && flags->precision == -1)
	{
		params[0] += params[1];
		params[1] = 0;
	}
	ft_conversion_cb_pad(flags, buffer, params, nb);
	free(nb_str);
	return (1);
}
