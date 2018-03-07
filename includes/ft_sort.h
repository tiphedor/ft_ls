/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:56:38 by msteffen          #+#    #+#             */
/*   Updated: 2018/03/07 13:58:02 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SORT_H
# define FT_SORT_H

# include "libft.h"
# include "ft_entry.h"

int		ft_sort_name(void *ev1, void *ev2);
void	ft_sort_result(t_list **lst_in, int (*cmp)(void*, void*), int reverse);

#endif
