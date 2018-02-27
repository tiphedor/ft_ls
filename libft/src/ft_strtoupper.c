/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:35:24 by msteffen          #+#    #+#             */
/*   Updated: 2017/12/04 17:01:01 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtoupper(const char *src)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!src)
		return (NULL);
	str = ft_strnew(ft_strlen(src));
	while (src[i])
	{
		str[i] = ft_toupper(src[i]);
		i++;
	}
	return (str);
}
