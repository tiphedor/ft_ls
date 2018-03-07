/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions_x_tools.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 10:55:09 by msteffen          #+#    #+#             */
/*   Updated: 2018/02/05 12:14:25 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERSIONS_X_TOOLS_H
# define FT_CONVERSIONS_X_TOOLS_H

# include "ft_buffer.h"
# include "ft_buffer_operations.h"
# include "ft_flags.h"

int ft_conversion_x_dash(t_buffer *buffer, t_flags *flags, int *params,
		uint64_t nb);
int ft_conversion_x_norm(t_buffer *buffer, t_flags *flags, int *params,
		uint64_t nb);

#endif
