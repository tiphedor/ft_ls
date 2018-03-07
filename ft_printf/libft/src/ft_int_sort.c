/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 19:21:08 by msteffen          #+#    #+#             */
/*   Updated: 2017/12/01 19:23:17 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_int_sort(int *arr, unsigned int len)
{
	unsigned int	i;
	int				tmp;

	i = 0;
	while (i < len - 1)
	{
		if (arr[i + 1] < arr[i])
		{
			tmp = arr[i + 1];
			arr[i + 1] = arr[i];
			arr[i] = tmp;
			i = 0;
		}
		else
			i++;
	}
}
