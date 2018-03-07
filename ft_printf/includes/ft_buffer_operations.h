/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_operations.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 18:50:49 by msteffen          #+#    #+#             */
/*   Updated: 2018/02/05 10:22:12 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUFFER_OPERATIONS_H
# define FT_BUFFER_OPERATIONS_H

# include "ft_buffer.h"

int				ft_buffer_putnchar(t_buffer *buffer, char c, int n);
int				ft_buffer_putchar(t_buffer *buffer, char c);
int				ft_buffer_putstr(t_buffer *buffer, char *str);
int				ft_buffer_putnstr(t_buffer *buffer, char *str, int n);

#endif
