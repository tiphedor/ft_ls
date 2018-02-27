/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:19:07 by msteffen          #+#    #+#             */
/*   Updated: 2017/11/10 12:21:35 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (((char*)s) + i);
		i++;
	}
	if (c == '\0')
		return (((char*)s) + i);
	return (NULL);
}
