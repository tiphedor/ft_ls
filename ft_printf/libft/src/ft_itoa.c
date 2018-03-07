/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:09:43 by msteffen          #+#    #+#             */
/*   Updated: 2017/12/01 18:26:10 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_itoa_checkneg(int n, unsigned int *nb, unsigned int *nb_size,
	int *is_negative)
{
	if (n < 0)
	{
		(*nb_size)++;
		*is_negative = 1;
		*nb = -n;
	}
}

char		*ft_itoa(int n)
{
	unsigned int	nb_size;
	int				is_negative;
	unsigned int	i;
	unsigned int	nb;
	char			*res;

	i = 0;
	nb = n;
	is_negative = 0;
	nb_size = ft_intlen(nb);
	ft_itoa_checkneg(n, &nb, &nb_size, &is_negative);
	if ((res = ft_strnew(nb_size)) == 0)
		return (NULL);
	while (nb > 9)
	{
		res[nb_size - i - 1] = '0' + (nb % 10);
		nb /= 10;
		i++;
	}
	res[nb_size - i - 1] = '0' + (nb % 10);
	if (is_negative)
		res[0] = '-';
	return (res);
}
