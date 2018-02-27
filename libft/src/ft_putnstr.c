/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 13:59:16 by msteffen          #+#    #+#             */
/*   Updated: 2017/12/12 14:31:21 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_putnstr(int n, char const *s)
{
	if (s && n > 0)
		return (ft_putnstr_fd(n, s, STDOUT_FILENO));
	return (0);
}
