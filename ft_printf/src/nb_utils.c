/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 11:40:30 by msteffen          #+#    #+#             */
/*   Updated: 2018/02/05 09:55:17 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nb_utils.h"

char	*ft_itoau64_base(uint64_t nb, char *base)
{
	int			base_len;
	int			i;
	char		*res;
	uint64_t	nb_tmp;

	nb_tmp = nb;
	base_len = ft_strlen(base);
	i = (nb_tmp == 0) ? 1 : 0;
	while (nb_tmp > 0)
	{
		i++;
		nb_tmp /= base_len;
	}
	if ((res = ft_strnew(i)) == NULL)
		return (0);
	if (nb == 0)
		res[0] = base[0];
	while (nb > 0)
	{
		res[i - 1] = base[nb % base_len];
		nb /= base_len;
		i--;
	}
	return (res);
}

char	*ft_itoa64_base(int64_t nb, char *base)
{
	char	*res;
	int		i;

	if (nb >= 0)
		return (ft_itoau64_base(nb, base));
	res = ft_itoau64_base(-nb, base);
	i = ft_strlen(res) + 1;
	while (i != 0)
	{
		res[i] = res[i - 1];
		i--;
	}
	res[0] = '-';
	return (res);
}
