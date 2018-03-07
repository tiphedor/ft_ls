/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_average.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 19:11:49 by msteffen          #+#    #+#             */
/*   Updated: 2017/12/04 17:00:27 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_int_average(int *arr, unsigned int len)
{
	unsigned int	i;
	float			avg;

	i = 0;
	avg = 0;
	while (i < len)
	{
		avg += arr[i];
		i++;
	}
	return (avg / len);
}
