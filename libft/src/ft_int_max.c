/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 19:16:12 by msteffen          #+#    #+#             */
/*   Updated: 2017/12/04 17:00:40 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_int_max(int *arr, unsigned int len)
{
	unsigned int	i;
	int				max;

	i = 0;
	max = arr[i];
	while (i < len)
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	return (max);
}
