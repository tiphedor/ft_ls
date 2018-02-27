/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:00:28 by msteffen          #+#    #+#             */
/*   Updated: 2017/11/08 18:18:37 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isspace_trim(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

static void	ft_strtrim_bounds(char const *s, unsigned int *start,
	unsigned int *end)
{
	unsigned int i;

	i = 0;
	while (isspace_trim(s[i]))
		i++;
	*start = i;
	*end = *start;
	while (s[i])
	{
		if (!isspace_trim(s[i]))
			*end = i;
		i++;
	}
}

char		*ft_strtrim(char const *s)
{
	unsigned int	start;
	unsigned int	end;
	unsigned int	i;
	char			*str;

	start = 0;
	end = 0;
	if (!s)
		return (NULL);
	ft_strtrim_bounds(s, &start, &end);
	i = 0;
	str = ft_strnew((end - start) + 1);
	if (!str)
		return (NULL);
	while (start <= end)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	return (str);
}
