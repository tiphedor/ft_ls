/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 15:16:37 by msteffen          #+#    #+#             */
/*   Updated: 2018/02/05 17:02:34 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_strreplace_first(char *haystack, char *new_haystack,
		char *needle, char *new_needle)
{
	int start;

	if (ft_strstr(haystack, needle) == NULL)
		return (0);
	start = ft_strstr(haystack, needle) - haystack;
	ft_strncat(new_haystack, haystack, start);
	ft_strcat(new_haystack, new_needle);
	ft_strcat(new_haystack, haystack + start + ft_strlen(needle));
	return (1);
}

/*
** Replaces all occurences of needle in haystack with new_needle.
** 	haystack must be an allocated, null-terminated string
**	needle must be an allocated, null-terminated string
**	new_needle must be an allocated, null-terminated string
**	new_needle must be at most as long as needle, never longer
**			(causes a buffer overflow, NOT checked).
*/

char		*ft_strreplace(char *haystack, char *needle, char *new_needle)
{
	char *tmp;

	if (ft_strstr(haystack, needle) == NULL)
		return (haystack);
	tmp = ft_strnew(ft_strlen(haystack));
	ft_strreplace_first(haystack, tmp, needle, new_needle);
	free(haystack);
	return (ft_strreplace(tmp, needle, new_needle));
}
