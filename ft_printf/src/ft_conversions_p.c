/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:44:10 by msteffen          #+#    #+#             */
/*   Updated: 2018/02/05 16:12:38 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_conversions_p.h"

int	ft_conversion_p_pad(t_flags *flags, t_buffer *buffer,
	int nb_spaces, int nb_zeros)
{
	if (!flags->dash)
		ft_buffer_putnchar(buffer, ' ', nb_spaces);
	ft_buffer_putstr(buffer, "0x");
	ft_buffer_putnchar(buffer, '0', nb_zeros);
	return (0);
}

int	ft_conversion_p(t_flags *flags, va_list *args, t_buffer *buffer)
{
	uint64_t	nb;
	char		*nb_str;
	int			nb_spaces;
	int			nb_zeros;

	nb = va_arg(*args, unsigned long int);
	nb_str = ft_itoau64_base(nb, "0123456789abcdef");
	nb_zeros = flags->precision - ft_strlen(nb_str);
	nb_spaces = flags->width - ft_strlen(nb_str) - 2;
	if (nb_zeros > 0)
		nb_spaces -= nb_zeros;
	nb_zeros = (nb_zeros < 0) ? 0 : nb_zeros;
	if (flags->zero && flags->precision == -1)
	{
		nb_zeros += nb_spaces;
		nb_spaces = 0;
	}
	ft_conversion_p_pad(flags, buffer, nb_spaces, nb_zeros);
	if (flags->precision != 0 || nb != 0)
		ft_buffer_putstr(buffer, nb_str);
	if (flags->dash)
		ft_buffer_putnchar(buffer, ' ', nb_spaces);
	free(nb_str);
	return (1);
}
