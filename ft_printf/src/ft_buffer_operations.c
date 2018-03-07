/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 18:51:34 by msteffen          #+#    #+#             */
/*   Updated: 2018/02/05 10:11:00 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer_operations.h"

int			ft_buffer_putchar(t_buffer *buffer, char c)
{
	if (realloc_buffer(buffer, 10) == 0)
		return (0);
	buffer->buffer_str[buffer->len] = c;
	buffer->buffer_str[buffer->len + 1] = 0;
	buffer->len += 1;
	return (1);
}

int			ft_buffer_putnchar(t_buffer *buffer, char c, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_buffer_putchar(buffer, c);
		i++;
	}
	return (1);
}

int			ft_buffer_putstr(t_buffer *buffer, char *str)
{
	if (realloc_buffer(buffer, ft_strlen(str)) == 0)
		return (0);
	ft_memcpy(buffer->buffer_str + buffer->len, str, ft_strlen(str));
	buffer->len += ft_strlen(str);
	return (1);
}

int			ft_buffer_putnstr(t_buffer *buffer, char *str, int n)
{
	if (n < 0)
		return (-1);
	if (realloc_buffer(buffer, ft_strlen(str) - n) == 0)
		return (0);
	ft_memcpy(buffer->buffer_str + buffer->len, str, n);
	if (n > (int)ft_strlen(str))
		buffer->len += (int)ft_strlen(str);
	else
		buffer->len += n;
	return (1);
}
