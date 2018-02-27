/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:18:58 by msteffen          #+#    #+#             */
/*   Updated: 2017/12/01 22:39:10 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*strn;
	unsigned int	i;

	i = 0;
	if (!s || (strn = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	while (s[i])
	{
		strn[i] = f(s[i]);
		i++;
	}
	return (strn);
}
