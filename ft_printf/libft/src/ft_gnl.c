/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:23:50 by msteffen          #+#    #+#             */
/*   Updated: 2018/01/17 18:25:44 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static int	gnl_copy_buffer(char *buffer, int *buff_position, char **line,
	int *flag)
{
	char	*search;

	if (*buff_position == -1)
		return (0);
	search = ft_strchr(buffer + *buff_position, '\n');
	if (search == NULL)
	{
		*line = ft_strdup(buffer + *buff_position);
		if (*line == NULL)
			return (-1);
		*buff_position = -1;
		*flag = 1;
		return (0);
	}
	else
	{
		*line = ft_strndup(buffer + *buff_position,
			search - buffer - *buff_position);
		if (*line == NULL)
			return (-1);
		*buff_position = (search - buffer) + 1;
		return (1);
	}
}

static int	gnl_copy_fd(const int fd, char *buffer, int *buff_position,
	char **line)
{
	char	*search;
	char	*tmp;
	int		read_len;

	while ((read_len = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[read_len] = 0;
		if ((search = ft_strchr(buffer, '\n')) == NULL)
		{
			if ((tmp = ft_strjoin(*line, buffer)) == NULL)
				return (-1);
			free(*line);
			*line = tmp;
		}
		else
		{
			*buff_position = (search - buffer) + 1;
			if ((tmp = ft_strnjoin(*line, buffer, search - buffer)) == NULL)
				return (-1);
			free(*line);
			*line = tmp;
			return (1);
		}
	}
	return (0);
}

int			ft_gnl(const int fd, char **line)
{
	static char	buffer[BUFF_SIZE + 1];
	static int	buff_position;
	int			flag;

	flag = 0;
	if (BUFF_SIZE < 0 || fd < 0 || line == NULL || read(fd, NULL, 0) < 0)
		return (-1);
	if (gnl_copy_buffer(buffer, &buff_position, line, &flag) == 1)
		return (1);
	if (gnl_copy_fd(fd, buffer, &buff_position, line) == 1)
		return (1);
	if (ft_strlen(*line) > 0 && flag)
		return (1);
	return (0);
}
