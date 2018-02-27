/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:48:58 by msteffen          #+#    #+#             */
/*   Updated: 2017/12/08 17:12:43 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnbr_recurs(int nbr, char *base, int base_length, int fd)
{
	int len;

	if (nbr != 0)
	{
		len = 1 + ft_putnbr_recurs(nbr / base_length, base, base_length, fd);
		ft_putchar_fd(base[nbr % base_length], fd);
		return (len);
	}
	return (0);
}

static int	base_check(char *base)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[y] == '-')
			return (0);
		while (base[y] != '\0')
		{
			if (base[i] == base[y] && i != y)
				return (0);
			y++;
		}
		i++;
	}
	return (1);
}

int			ft_putnbr_base_fd(int fd, int nbr, char *base)
{
	int		base_size;
	long	nb;

	nb = nbr;
	base_size = ft_strlen(base);
	if (nbr == 0)
	{
		ft_putchar_fd('0', fd);
		return (1);
	}
	if (base_size <= 1)
		return (-1);
	if (!base_check(base))
		return (-1);
	if (nb < 0)
		return (-1);
	return (ft_putnbr_recurs(nb, base, base_size, fd));
}
