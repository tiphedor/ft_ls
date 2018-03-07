/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 12:32:00 by msteffen          #+#    #+#             */
/*   Updated: 2018/03/05 11:10:11 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_params.h"

t_lsparams	*ft_ls_create_params(void)
{
	t_lsparams	*params;

	params = (t_lsparams*)malloc(sizeof(t_lsparams));
	params->l = 0;
	params->cr = 0;
	params->a = 0;
	params->r = 0;
	params->t = 0;
	return (params);
}
void		ft_ls_destroy_params(t_lsparams **params)
{
	free(*params);
	*params = NULL;
}

int ft_parse_error(int c)
{
	ft_printf_fd(STDERR_FILENO, "ft_ls: illegal option -- %c\nusage: ft_ls [-lRart] [file ...]\n", c);
	return (-1);
}

int ft_legal_param(int c)
{
	return (c == 'l' || c == 'R' || c == 'a' || c == 'r' || c == 't');
}

void ft_update_params(t_lsparams *params, int c)
{
	if (c == 'l')
		params->l = 1;
	if (c == 'R')
		params->cr = 1;
	if (c == 'a')
		params->a = 1;
	if (c == 'r')
		params->r = 1;
	if (c == 't')
		params->t = 1;
}

int 		ft_ls_parse_params(t_lsparams *params, int ac, char **av)
{
	int i;
	int y;

	i = 1;
	while (i < ac)
	{
		y = 0;
		if (av[i][0] && av[i][1] && av[i][0] == '-' && av[i][1] == '-' && av[i][2]) // -- => End of arguments
			return (ft_parse_error('-'));
		if (av[i][0] && av[i][1] && av[i][0] == '-' && av[i][1] == '-') // -- => End of arguments
			return (1);
		if (av[i][0] && av[i][0] == '-')
		{
			y++;
			while (av[i][y])
			{
				if (ft_legal_param(av[i][y]))
					ft_update_params(params, av[i][y]);
				else
					return (ft_parse_error(av[i][y]));
				y++;
			}
		}
		else
			return (i);
		i++;
	}
	return (i);
}
