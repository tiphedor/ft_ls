/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:23:51 by msteffen          #+#    #+#             */
/*   Updated: 2017/11/10 13:52:10 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static unsigned int	ft_strsplit_countgroups(char const *s, char c)
{
	unsigned int group_count;
	unsigned int i;

	group_count = 0;
	i = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			group_count++;
		if (s[i] == c && s[i + 1] != '\0' && s[i + 1] != c)
			group_count++;
		i++;
	}
	return (group_count);
}

static unsigned int	ft_strsplit_grouplen(char const *s, char c, unsigned int n)
{
	unsigned int group_count;
	unsigned int group_len;
	unsigned int i;

	group_count = 0;
	group_len = 0;
	i = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c)
			|| (s[i] == c && s[i + 1] != '\0' && s[i + 1] != c))
		{
			if (group_count == n)
			{
				if (s[i] == c)
					i++;
				while (s[i] && s[i++] != c)
					group_len++;
				return (group_len);
			}
			group_count++;
		}
		i++;
	}
	return (0);
}

static void			ft_strsplit_fill(char *dest, char const *s, char c,
	unsigned int n)
{
	unsigned int group_count;
	unsigned int i;
	unsigned int y;

	group_count = 0;
	i = 0;
	y = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c)
			|| (s[i] == c && s[i + 1] != '\0' && s[i + 1] != c))
		{
			if (group_count == n)
			{
				if (s[i] == c)
					i++;
				while (s[i] && s[i++] != c)
					dest[y++] = s[i - 1];
				return ;
			}
			group_count++;
		}
		i++;
	}
}

char				**ft_strsplit(char const *s, char c)
{
	unsigned int	group_count;
	unsigned int	i;
	char			**res;

	if (!s)
		return (NULL);
	i = 0;
	group_count = ft_strsplit_countgroups(s, c);
	res = (char **)ft_memalloc(sizeof(char*) * (group_count + 1));
	if (!res)
		return (NULL);
	while (i < group_count)
	{
		res[i] = ft_strnew(ft_strsplit_grouplen(s, c, i));
		if (!res[i])
			return (NULL);
		ft_strsplit_fill(res[i], s, c, i);
		i++;
	}
	res[i] = 0;
	return (res);
}
