/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 11:40:46 by msteffen          #+#    #+#             */
/*   Updated: 2018/02/05 10:23:05 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NB_UTILS_H
# define NB_UTILS_H

# include "libft.h"
# include <stdint.h>

char	*ft_itoau64_base(uint64_t nb, char *base);
char	*ft_itoa64_base(int64_t nb, char *base);

#endif
