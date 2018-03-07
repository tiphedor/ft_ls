/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:58:07 by msteffen          #+#    #+#             */
/*   Updated: 2017/11/13 11:08:07 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*s_char;

	i = 0;
	s_char = ((unsigned char *)s);
	while (i < n)
	{
		if (s_char[i] == (unsigned char)c)
			return (s_char + i);
		i++;
	}
	return (NULL);
}
