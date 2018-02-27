/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 19:16:07 by msteffen          #+#    #+#             */
/*   Updated: 2017/12/04 17:00:50 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_int_min(int *arr, unsigned int len)
{
	unsigned int	i;
	int				min;

	i = 0;
	min = arr[i];
	while (i < len)
	{
		if (arr[i] < min)
			min = arr[i];
		i++;
	}
	return (min);
}
