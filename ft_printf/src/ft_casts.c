/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_casts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:07:55 by msteffen          #+#    #+#             */
/*   Updated: 2018/01/15 18:56:02 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_casts.h"

int64_t		ft_cast_signed(t_flags *flags, va_list *args)
{
	if (flags->hh)
		return ((signed char)va_arg(*args, int));
	if (flags->h)
		return ((short int)va_arg(*args, int));
	if (flags->l)
		return (va_arg(*args, long int));
	if (flags->ll)
		return (va_arg(*args, long long int));
	if (flags->j)
		return (va_arg(*args, intmax_t));
	if (flags->z)
		return (va_arg(*args, size_t));
	return (va_arg(*args, int));
}

uint64_t	ft_cast_unsigned(t_flags *flags, va_list *args)
{
	if (flags->hh)
		return ((unsigned char)va_arg(*args, int));
	if (flags->h)
		return ((unsigned short)va_arg(*args, int));
	if (flags->l)
		return (va_arg(*args, unsigned long int));
	if (flags->ll)
		return (va_arg(*args, unsigned long long int));
	if (flags->j)
		return (va_arg(*args, uintmax_t));
	if (flags->z)
		return (va_arg(*args, size_t));
	return (va_arg(*args, unsigned int));
}
