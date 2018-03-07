/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:51:33 by msteffen          #+#    #+#             */
/*   Updated: 2017/12/01 22:28:47 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	y;

	y = 0;
	if (!s || (str = ft_strnew(len)) == NULL)
		return (NULL);
	while (y < len)
	{
		str[y] = s[start];
		y++;
		start++;
	}
	str[y] = '\0';
	return (str);
}
