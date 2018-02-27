/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:46:29 by msteffen          #+#    #+#             */
/*   Updated: 2017/12/01 22:38:15 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*strn;
	unsigned int	i;

	i = 0;
	if (!s || (strn = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	while (s[i])
	{
		strn[i] = f(i, s[i]);
		i++;
	}
	return (strn);
}
