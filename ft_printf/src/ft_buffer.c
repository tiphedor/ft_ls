/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:19:59 by msteffen          #+#    #+#             */
/*   Updated: 2018/02/07 11:58:06 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer.h"

t_buffer	*buffer_init(void)
{
	t_buffer *buffer;

	if ((buffer = (t_buffer*)malloc(sizeof(t_buffer))) == 0)
		return (0);
	buffer->buffer_str = ft_strnew(32);
	buffer->allocated = 32;
	buffer->len = 0;
	return (buffer);
}

int			realloc_buffer(t_buffer *buffer, int target_size)
{
	char *tmp;

	if ((int)ft_strlen(buffer->buffer_str) + target_size < buffer->allocated)
		return (1);
	if ((tmp = ft_strnew(ft_strlen(buffer->buffer_str))) == NULL)
		return (0);
	ft_memcpy(tmp, buffer->buffer_str, buffer->len);
	free(buffer->buffer_str);
	buffer->allocated = buffer->allocated + target_size + 2;
	if ((buffer->buffer_str = ft_strnew(buffer->allocated)) == NULL)
		return (0);
	ft_memcpy(buffer->buffer_str, tmp, buffer->len);
	free(tmp);
	return (1);
}

int			ft_dump_buffer(t_buffer *buffer, int fd)
{
	int ret;

	write(fd, buffer->buffer_str, buffer->len);
	ret = buffer->len;
	ft_destroy_buffer(buffer);
	return (ret);
}

int			ft_destroy_buffer(t_buffer *buffer)
{
	free(buffer->buffer_str);
	free(buffer);
	return (-1);
}
