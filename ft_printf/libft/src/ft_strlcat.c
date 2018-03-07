/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:34:35 by msteffen          #+#    #+#             */
/*   Updated: 2017/11/08 18:10:19 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t			ret;
	unsigned int	y;
	unsigned int	i;

	i = 0;
	y = 0;
	ret = ft_strlen(dest);
	if (size < ft_strlen(dest))
		return (ft_strlen(src) + size);
	while (dest[i] && i < size)
		i++;
	while (src[y] && i + y < size - 1)
	{
		dest[i + y] = src[y];
		y++;
	}
	dest[i + y] = 0;
	return (ret + ft_strlen(src));
}
