/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:36:40 by msteffen          #+#    #+#             */
/*   Updated: 2018/02/27 21:46:07 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls_params.h"
#include <stdio.h>
#include "libft.h"
#include "ft_entry.h"
#include <sys/types.h>
#include <sys/stat.h>
#include "ft_list.h"
#include <unistd.h>
#include <dirent.h>

int ft_ls_path(char *path, t_lsparams *params, t_lslist *lst);

void ft_print_list_l_permissions(t_entry *entry) // @todo pas de l pour les symlinks
{
	printf("%c", entry->o_r ? 'r' : '-');
	printf("%c", entry->o_w ? 'w' : '-');
	printf("%c", entry->o_x ? 'x' : '-');
	printf("%c", entry->g_r ? 'r' : '-');
	printf("%c", entry->g_w ? 'w' : '-');
	printf("%c", entry->g_x ? 'x' : '-');
	printf("%c", entry->w_r ? 'r' : '-');
	printf("%c", entry->w_w ? 'w' : '-');
	printf("%c", entry->w_x ? 'x' : '-');
}

void ft_get_max_lens(t_lslist *lst, int *max_byte_len, int *max_link_len, int *total_blk_sz)
{
	int i;

	i = 1;
	*max_byte_len = ft_intlen(lst->arr[i]->sz_bytes);
	*max_link_len = ft_intlen(lst->arr[i]->nb_links);
	*total_blk_sz = lst->arr[0]->sz_blocks;
	while (i < lst->used_size)
	{
		if (ft_intlen(lst->arr[i]->nb_links) > *max_link_len)
			*max_link_len = ft_intlen(lst->arr[i]->nb_links);
		if (ft_intlen(lst->arr[i]->sz_bytes) > *max_byte_len)
			*max_byte_len = ft_intlen(lst->arr[i]->sz_bytes);
		*total_blk_sz += lst->arr[i]->sz_blocks;
		i++;
	}
}

void ft_print_pad(int nb)
{
	int i;

	i = -1;
	while (++i <= nb)
		printf(" ");
}

void ft_print_list_l(t_lslist *lst)
{
	int i;
	int max_byte_len;
	int max_link_len;
	int total;
	t_entry *current;

	i = 0;
	ft_get_max_lens(lst, &max_byte_len, &max_link_len, &total);
	printf("total %d\n", total);
	while (i < lst->used_size)
	{
		current = lst->arr[i];
		printf("%c", current->type);
		ft_print_list_l_permissions(current);
		ft_print_pad(max_link_len - ft_intlen(current->nb_links));
		printf(" %d ", current->nb_links);
		printf("%s", current->user);
		printf("  %s", current->group);
		ft_print_pad(max_byte_len - ft_intlen(current->sz_bytes));
		printf(" %d ", current->sz_bytes);
		printf("%.12s", current->last_edit_date);
		printf(" %s", current->name);
		printf("\n");
		i++;
	}
}

void ft_print_list(t_lslist *lst)
{
	int i;

	i = 0;
	if (lst->used_size == 1)
	{
		printf("%s\n", lst->arr[0]->name);
		return ;
	}
	while (i < lst->used_size)
	{
		if (i == 0)
			printf("%s", lst->arr[i]->name);
		else if (i == lst->used_size - 1)
			printf("\t%s\n", lst->arr[i]->name);
		else
			printf("\t%s", lst->arr[i]->name);
		i++;
	}
}

int ft_ls_read_dir(char *path, t_lsparams *params, t_lslist *lst)
{
	DIR				*dir_fd;
	struct dirent	*dir_data;
	t_entry			*entry;

	dir_fd = opendir(path);
	if (dir_fd)
	{
		while ((dir_data = readdir(dir_fd)) != NULL)
		{
			if (!ft_strequ(dir_data->d_name, ".") && !ft_strequ(dir_data->d_name, "..") && dir_data->d_name[0] != '.')
			{
				entry = create_entry_file(dir_data->d_name);
				ft_list_push(lst, entry);
			}
			(void)params;
		}
		closedir(dir_fd);
	}
	else
	{
		printf("\n\n\n\n\n ERROR NON GERER; OPENDIR A RETOURNE 0 \n\n\n\n\n\n"); //@todo
		return (4);
	}
	return (0);
}

int ft_ls_path(char *path, t_lsparams *params, t_lslist *lst)
{
	struct stat stated;
	t_entry *entry;

	if (stat(path, &stated) != 0) // path does not exists
	{
		printf("ft_ls: %s: No such file or directory\n", path);
		return (1);
	}
	if (S_ISREG(stated.st_mode) || S_ISLNK(stated.st_mode)) // path point to a single regular file
	{
		entry = create_entry_file(path);
		ft_list_push(lst, entry);
		return (0);
	}
	else // path points to a directory
		return (ft_ls_read_dir(path, params, lst));
}

int ft_ls(int ac, char **av, t_lsparams *params, int path_start)
{
	int i;
	int err;
	t_lslist *lst;

	err = 0;
	lst = ft_list_init();
	i = path_start;
	if (path_start == ac)
		ft_ls_path(".", params, lst);
	while (i < ac)
	{
		if (ft_ls_path(av[i], params, lst) == 1)
			err = 1;
		i++;
	}
	ft_list_sort_name(lst);
	if (params->l)
		ft_print_list_l(lst);
	else
		ft_print_list(lst);
	ft_list_destroy(&lst);
	return (err);
}

int main(int ac, char **av)
{
	t_lsparams *params;
	int path_start;
	int err;

	params = ft_ls_create_params();
	path_start = ft_ls_parse_params(params, ac, av);
	if (path_start < 0)
		return (1);


	err = ft_ls(ac, av, params, path_start);
	ft_ls_destroy_params(&params);

	return (err); // @todo remplacer printf => ft_printf
}
