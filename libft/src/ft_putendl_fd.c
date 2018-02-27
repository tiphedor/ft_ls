/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:16:40 by msteffen          #+#    #+#             */
/*   Updated: 2017/12/08 18:09:26 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(char const *s, int fd)
{
	if (!s)
		return (0);
	return (ft_putstr_fd(s, fd) + ft_putchar_fd('\n', fd));
}
