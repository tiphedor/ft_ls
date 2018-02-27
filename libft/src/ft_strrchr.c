/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:24:56 by msteffen          #+#    #+#             */
/*   Updated: 2017/11/10 12:27:32 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*res;

	res = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			res = ((char*)s) + i;
		i++;
	}
	if (c == '\0')
		return (((char*)s) + i);
	return (res);
}
