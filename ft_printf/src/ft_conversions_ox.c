/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions_ox.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:20:51 by msteffen          #+#    #+#             */
/*   Updated: 2018/02/05 16:27:42 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_conversions_ox.h"

int	ft_conversion_x(t_flags *flags, va_list *args, t_buffer *buffer)
{
	uint64_t	nb;
	int			params[2];
	char		*nb_str;

	nb = ft_cast_unsigned(flags, args);
	nb_str = ft_itoau64_base(nb, "0123456789abcdef");
	params[0] = flags->precision - ft_strlen(nb_str);
	if (params[0] < 0)
		params[0] = 0;
	params[1] = flags->width - ft_strlen(nb_str) - params[0];
	free(nb_str);
	if (flags->dash)
		return (ft_conversion_x_dash(buffer, flags, params, nb));
	else
		return (ft_conversion_x_norm(buffer, flags, params, nb));
	return (1);
}

int	ft_conversion_cx(t_flags *flags, va_list *args, t_buffer *buffer)
{
	uint64_t	nb;
	int			params[2];
	char		*nb_str;

	nb = ft_cast_unsigned(flags, args);
	nb_str = ft_itoau64_base(nb, "0123456789ABCDEF");
	params[0] = flags->precision - ft_strlen(nb_str);
	if (params[0] < 0)
		params[0] = 0;
	params[1] = flags->width - ft_strlen(nb_str) - params[0];
	free(nb_str);
	if (flags->dash)
		return (ft_conversion_cx_dash(buffer, flags, params, nb));
	else
		return (ft_conversion_cx_norm(buffer, flags, params, nb));
	return (1);
}

int	ft_conversion_o_pad(t_flags *flags, t_buffer *buffer, int *params,
	uint64_t nb)
{
	char *nb_str;

	nb_str = ft_itoau64_base(nb, "01234567");
	if (!flags->dash)
		ft_buffer_putnchar(buffer, ' ', params[1]);
	if ((flags->hash && nb != 0)
		|| (nb == 0 && flags->precision == 0 && flags->hash))
		ft_buffer_putstr(buffer, "0");
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

int	ft_conversion_o(t_flags *flags, va_list *args, t_buffer *buffer)
{
	uint64_t	nb;
	char		*nb_str;
	int			params[2];

	nb = ft_cast_unsigned(flags, args);
	nb_str = ft_itoau64_base(nb, "01234567");
	params[0] = flags->precision - ft_strlen(nb_str) - (flags->hash && nb != 0);
	params[1] = flags->width - ft_strlen(nb_str) - (flags->hash && nb != 0);
	if (params[0] > 0)
		params[1] -= params[0];
	params[0] = (params[0] < 0) ? 0 : params[0];
	if (!flags->dash && flags->zero && flags->precision == -1)
	{
		params[0] += params[1];
		params[1] = 0;
	}
	ft_conversion_o_pad(flags, buffer, params, nb);
	free(nb_str);
	return (1);
}

int	ft_conversion_co(t_flags *flags, va_list *args, t_buffer *buffer)
{
	flags->hh = 0;
	flags->j = 0;
	flags->z = 0;
	flags->hh = 0;
	flags->h = 0;
	flags->l = 0;
	flags->ll = 1;
	return (ft_conversion_o(flags, args, buffer));
}
