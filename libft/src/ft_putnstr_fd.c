/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 13:59:31 by msteffen          #+#    #+#             */
/*   Updated: 2017/12/12 14:31:37 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnstr_fd(int n, char const *s, int fd)
{
	int i;

	i = 0;
	if (!s || n <= 0)
		return (0);
	while (i < n && s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	return (i);
}
