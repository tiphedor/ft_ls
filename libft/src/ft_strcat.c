/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:01:16 by msteffen          #+#    #+#             */
/*   Updated: 2017/12/01 22:46:48 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	unsigned int i;
	unsigned int y;

	i = 0;
	y = 0;
	while (s1[i])
		i++;
	while (s2[y])
	{
		s1[i] = s2[y];
		y++;
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
