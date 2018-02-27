/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:43:56 by msteffen          #+#    #+#             */
/*   Updated: 2017/11/13 11:08:57 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int i;
	unsigned int y;

	if (needle[0] == '\0')
		return ((char*)haystack);
	i = 0;
	while (haystack[i])
	{
		y = 0;
		while (haystack[i + y] == needle[y])
		{
			if (needle[y + 1] == '\0')
				return ((char*)haystack + i);
			y++;
		}
		i++;
	}
	return (NULL);
}
