/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions_diu.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:05:12 by msteffen          #+#    #+#             */
/*   Updated: 2018/02/05 12:20:55 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_conversions_diu.h"

int	ft_conversion_d_pad(int *params, t_flags *flags, int64_t nb,
		t_buffer *buffer)
{
	if (params[0] > 0)
		params[1] -= params[0];
	if (params[0] < 0)
		params[0] = 0;
	if (!flags->dash && flags->zero && flags->precision == -1)
	{
		params[0] += params[1];
		params[1] = 0;
	}
	if (nb == 0 && flags->precision == 0)
		params[1]++;
	if (flags->plus && flags->zero && nb < 0)
		params[0]++;
	if (!flags->dash)
		ft_buffer_putnchar(buffer, ' ', params[1]);
	if (params[2])
		ft_buffer_putchar(buffer, '-');
	if (flags->plus && nb >= 0)
		ft_buffer_putchar(buffer, '+');
	else if (flags->space && nb >= 0)
		ft_buffer_putchar(buffer, ' ');
	return (1);
}

int	ft_conversion_d(t_flags *flags, va_list *args, t_buffer *buffer)
{
	int64_t	nb;
	char	*nb_str;
	int		params[3];

	params[2] = 0;
	nb = ft_cast_signed(flags, args);
	if (nb < 0)
	{
		nb_str = ft_itoau64_base(-nb, "0123456789");
		params[2] = 1;
	}
	else
		nb_str = ft_itoa64_base(nb, "0123456789");
	params[0] = flags->precision - ft_strlen(nb_str);
	params[1] = flags->width - ft_strlen(nb_str) - (params[2] == 1) -
		(flags->space) - (flags->plus) + (flags->space && flags->plus);
	ft_conversion_d_pad(params, flags, nb, buffer);
	ft_buffer_putnchar(buffer, '0', params[0]);
	if (flags->precision != 0 || nb != 0)
		ft_buffer_putstr(buffer, nb_str);
	if (flags->dash)
		ft_buffer_putnchar(buffer, ' ', params[1]);
	free(nb_str);
	return (1);
}

int	ft_conversion_cd(t_flags *flags, va_list *args, t_buffer *buffer)
{
	flags->hh = 0;
	flags->j = 0;
	flags->z = 0;
	flags->hh = 0;
	flags->h = 0;
	flags->l = 0;
	flags->ll = 1;
	return (ft_conversion_d(flags, args, buffer));
}

int	ft_conversion_u(t_flags *flags, va_list *args, t_buffer *buffer)
{
	uint64_t	nb;
	char		*nb_str;
	int			params[2];

	nb = ft_cast_unsigned(flags, args);
	nb_str = ft_itoau64_base(nb, "0123456789");
	params[0] = flags->precision - ft_strlen(nb_str);
	params[1] = flags->width - ft_strlen(nb_str);
	if (params[0] > 0)
		params[1] -= params[0];
	params[0] = (params[0] < 0) ? 0 : params[0];
	if (flags->zero && flags->precision == -1)
	{
		params[0] += params[1];
		params[1] = 0;
	}
	if (!flags->dash)
		ft_buffer_putnchar(buffer, ' ', params[1]);
	ft_buffer_putnchar(buffer, '0', params[0]);
	if (flags->precision != 0 || nb != 0)
		ft_buffer_putstr(buffer, nb_str);
	if (flags->dash)
		ft_buffer_putnchar(buffer, ' ', params[1]);
	free(nb_str);
	return (1);
}

int	ft_conversion_cu(t_flags *flags, va_list *args, t_buffer *buffer)
{
	flags->hh = 0;
	flags->j = 0;
	flags->z = 0;
	flags->hh = 0;
	flags->h = 0;
	flags->l = 0;
	flags->ll = 1;
	return (ft_conversion_u(flags, args, buffer));
}
