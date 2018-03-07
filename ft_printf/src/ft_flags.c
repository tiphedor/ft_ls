/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:09:24 by msteffen          #+#    #+#             */
/*   Updated: 2018/02/05 10:37:11 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_flags.h"

void			ft_init_flags(t_flags *flags)
{
	flags->hash = 0;
	flags->zero = 0;
	flags->dash = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->width = 0;
	flags->precision = -1;
	flags->j = 0;
	flags->z = 0;
	flags->hh = 0;
	flags->h = 0;
	flags->l = 0;
	flags->ll = 0;
	flags->percent_holder = 0;
}

static int		ft_parse_flags_length(const char *str, t_flags *flags)
{
	int i;

	i = 0;
	if (str[i] == 'j')
		flags->j = 1;
	else if (str[i] == 'z')
		flags->z = 1;
	else if (str[i] == 'h' && str[i + 1] && str[i + 1] == 'h')
		flags->hh = 1;
	else if (str[i] == 'h')
		flags->h = 1;
	else if (str[i] == 'l' && str[i + 1] && str[i + 1] == 'l')
		flags->ll = 1;
	else if (str[i] == 'l')
		flags->l = 1;
	if (flags->j || flags->z || flags->h || flags->l)
		return (1);
	if (flags->hh || flags->ll)
		return (2);
	return (0);
}

static int		ft_parse_flags_fieldprecision(const char *str, t_flags *flags)
{
	int i;

	i = 0;
	if (ft_isdigit(str[i]))
	{
		flags->width = ft_atoi(str + i);
		i += ft_intlen(flags->width);
	}
	if (str[i] == '.' && ft_isdigit(str[i + 1]))
	{
		flags->precision = ft_atoi(str + i + 1);
		i += ft_intlen(flags->precision) + 1;
	}
	else if (str[i] == '.')
	{
		flags->precision = 0;
		i++;
	}
	return (i);
}

static int		ft_parse_flags_flags(const char *str, t_flags *flags)
{
	int i;

	i = 0;
	while (str[i] && ft_isoneof(str[i], "#0-+ "))
	{
		if (str[i] == '#')
			flags->hash = 1;
		if (str[i] == '0')
			flags->zero = 1;
		if (str[i] == '-')
			flags->dash = 1;
		if (str[i] == '+')
			flags->plus = 1;
		if (str[i] == ' ')
			flags->space = 1;
		i++;
	}
	return (i);
}

int				ft_parse_flags(const char *str, t_flags *flags)
{
	int i;

	i = 0;
	ft_init_flags(flags);
	i += ft_parse_flags_flags(str, flags);
	i += ft_parse_flags_fieldprecision(str + i, flags);
	i += ft_parse_flags_length(str + i, flags);
	return (i + 1);
}
