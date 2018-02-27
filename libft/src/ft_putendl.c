/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:28:17 by msteffen          #+#    #+#             */
/*   Updated: 2017/12/08 18:09:41 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_putendl(char const *s)
{
	if (s)
		return (ft_putendl_fd(s, STDOUT_FILENO));
	return (0);
}
