/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:25:21 by msteffen          #+#    #+#             */
/*   Updated: 2017/12/01 18:25:23 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(unsigned int n)
{
	unsigned int sz;
	unsigned int nb;

	nb = ft_abs(n);
	sz = 1;
	while (nb > 9)
	{
		nb /= 10;
		sz++;
	}
	return (sz);
}
