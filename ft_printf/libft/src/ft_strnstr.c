/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:00:56 by msteffen          #+#    #+#             */
/*   Updated: 2017/11/13 11:09:26 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	unsigned int i;
	unsigned int y;

	if (needle[0] == '\0')
		return ((char*)haystack);
	i = 0;
	while (haystack[i] && i < n)
	{
		y = 0;
		while (haystack[i + y] == needle[y] && i + y < n)
		{
			if (needle[y + 1] == '\0')
				return ((char*)haystack + i);
			y++;
		}
		i++;
	}
	return (NULL);
}
