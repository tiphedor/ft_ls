/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:14:54 by msteffen          #+#    #+#             */
/*   Updated: 2017/12/08 18:13:27 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char const *s, int fd)
{
	int i;

	i = -1;
	if (!s)
		return (0);
	while (s[++i])
		ft_putchar_fd(s[i], fd);
	return (i);
}
