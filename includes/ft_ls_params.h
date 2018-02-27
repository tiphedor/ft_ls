/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_params.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 12:29:35 by msteffen          #+#    #+#             */
/*   Updated: 2018/02/27 12:46:51 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_PARAMS_H
# define FT_LS_PARAMS_H

# include <stdlib.h>
# include "libft.h"
# include <unistd.h>

typedef struct	s_lsparams
{
	int l;
	int cr;
	int a;
	int r;
	int t;
}				t_lsparams;

t_lsparams	*ft_ls_create_params(void);
void		ft_ls_destroy_params(t_lsparams **params);
int 		ft_ls_parse_params(t_lsparams *params, int ac, char **av);

#endif
