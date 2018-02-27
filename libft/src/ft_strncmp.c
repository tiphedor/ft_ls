/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:53:21 by msteffen          #+#    #+#             */
/*   Updated: 2017/11/08 16:42:30 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *sstr1, const char *sstr2, size_t num)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)sstr1;
	str2 = (unsigned char *)sstr2;
	i = 0;
	while ((str1[i] || str2[i]) && i < num)
	{
		if (str2[i] > str1[i])
			return (str1[i] - str2[i]);
		if (str1[i] > str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
