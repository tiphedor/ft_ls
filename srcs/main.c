/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:05:53 by msteffen          #+#    #+#             */
/*   Updated: 2018/03/07 15:06:03 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_params.h"
#include "libft.h"
#include "ft_entry.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include "ft_sort.h"
#include "ft_ls_print_l.h"



void ft_del_entrylist(void *ptr, size_t len)
{
	t_entry *entry;

	entry = (t_entry*)ptr;
	destroy_entry(&entry);
	(void)len;
}

void ft_list_push(t_list **lst, t_entry *entry)
{
	if (*lst == NULL)
		*lst = ft_lstnew(entry, sizeof(t_entry));
	else
		ft_lstadd(lst, ft_lstnew(entry, sizeof(t_entry)));
}


char *ft_ls_pathcat(char *base_path, char *path)
{
	char	*res;

	if ((res = ft_strnew(ft_strlen(base_path) + ft_strlen(path) + 2)) == NULL)
		return (NULL);
	ft_strcpy(res, base_path);
	ft_strcat(res, "/");
	ft_strcat(res, path);
	return (res);
}


int ft_ls_path_dir(char *directory_path, t_entry *entry, t_lsparams *params)
{
	(void)params;

	t_entry			*current_file_entry;
	DIR				*dir_fd;
	char			*fullpath;
	struct dirent	*dir_data;

	dir_fd = opendir(directory_path);
	if (dir_fd)
	{
		while ((dir_data = readdir(dir_fd)) != NULL)
		{
			if (!ft_strequ(dir_data->d_name, ".") && !ft_strequ(dir_data->d_name, "..") && dir_data->d_name[0] != '.')
			{
				// dir_data->d_name[0] != '.' = > option -a
				fullpath = ft_ls_pathcat(directory_path, dir_data->d_name);
				current_file_entry = ft_parse_file_entry(fullpath, fullpath + ft_strlen(directory_path) + 1);
				if (params->cr)
					ft_ls_path_dir(fullpath, current_file_entry,  params);
				free(fullpath);
				ft_list_push(&(entry->subentries), current_file_entry);
			}
		}
		closedir(dir_fd);
	}
	return (0);

}

int ft_ls_path(char *path, t_list **lst, t_lsparams *params)
{
	t_entry *entry;

	entry = ft_parse_file_entry(path, NULL);
	if (entry == NULL)
	{
		ft_printf_fd(2, "ft_ls: %s: %s\n", path, strerror(errno));
		return (1);
	}
	if (entry->s_isdir)
	{
		ft_ls_path_dir(path, entry, params);
	}
	ft_list_push(lst, entry);
	return (0);
}


/*
**	Prints all entries from a list, without distinction.
*/
void ft_print_entries(t_list *lst, t_lsparams *params)
{
	t_entry *e;

	if (params->l)
	{
		ft_print_l_all(lst);
		return ;
	}
	while (lst)
	{
		e = (t_entry *)lst->content;
		if (lst->next)
			ft_printf("%s\t", e->name);
		else
			ft_printf("%s", e->name);
		lst = lst->next;
	}
}

/*
**	Prints simple entries (ie entries without subentries), ignores the others.
*/
int ft_print_simple_entries(t_list *lst, t_lsparams *params)
{
	t_entry *e;
	int has_prefix;

	has_prefix = 0;
	while (lst) {
		e = (t_entry *)lst->content;
		if (e->subentries == NULL)
		{
			has_prefix = 1;
			if (lst->next)
				ft_printf("TEK%s\t", e->name);
			else
				ft_printf("TEK%s", e->name);
		}
		lst = lst->next;
	}
	(void)params;
	return (has_prefix);
}

/**
**	Prints complex entry (ie entries with subentries), ignores the others.
*/
void ft_print_complex_entries(t_list *lst, t_lsparams *params)
{
	t_entry *e;

	while (lst)
	{
		e = (t_entry *)lst->content;
		if (e->subentries != NULL)
		{
			printf("%s: \n", e->name);
			ft_print_entries(e->subentries, params);
			if (lst->next)
				printf("\n");
		}
		lst = lst->next;
	}
}

/*
**	Prints all entries stored in lst_entries.
**	Used when sevral folders are passed and they need to have their content
**	grouped by folder.
*/
void ft_print_result_multipledirs(t_list *lst_entries, t_lsparams *params)
{
	t_list *lst;
	int has_prefix;

	lst = lst_entries;
	has_prefix = ft_print_simple_entries(lst, params);
	if (has_prefix)
		printf("\n\n");
	ft_print_complex_entries(lst, params);
}

/*
**	Prints all entries stored in lst.
*/
void ft_print_result_singledir(t_list *lst, t_lsparams *params)
{
	t_entry *e;

	e = (t_entry *)lst->content;
	if (e->subentries != NULL)
		ft_print_entries(e->subentries, params);
	else
		ft_print_entries(lst, params);
}

void ft_print_result(t_list *lst_entries, t_lsparams *params)
{
	t_list	*keep;
	t_list	*lst;
	t_entry	*e;

	keep = lst_entries;
	lst = keep;
	int nb_entries_withsub = 0;
	int nb_entries_withoutsub = 0;
	while (lst)
	{
		e = (t_entry *)lst->content;
		if (e->subentries != NULL)
			nb_entries_withsub++;
		else
			nb_entries_withoutsub++;
		lst = lst->next;
	}
	if (nb_entries_withsub > 1
	|| (nb_entries_withsub == 1 && nb_entries_withoutsub != 0))
		ft_print_result_multipledirs(lst_entries, params);
	else
		ft_print_result_singledir(lst_entries, params);
}

int ft_ls(t_lsparams *params, int ac, char **av, int path_start)
{
	int			i;
	int			err;
	t_list		*lst;

	err = 0;
	lst = NULL;
	i = path_start;
	if (path_start == ac)
	{
		ft_ls_path(".", &lst, params);
	}
	while (i < ac)
	{
		if (ft_ls_path(av[i], &lst, params) == 1)
			err = 1;
		i++;
	}

	if (params->r)
		ft_sort_result(&lst, &ft_sort_name, 0);
	else
		ft_sort_result(&lst, &ft_sort_name, 1);



	ft_print_result(lst, params);

	//ft_lstdel(&lst, &ft_del_entrylist); @todo free
	return (err);
}

int	main(int ac, char **av)
{
	t_lsparams	*params;
	int			start;

	params = ft_ls_create_params();
	start = ft_ls_parse_params(params, ac, av);

	if (start < 0)
		return (1);

	int ret = ft_ls(params, ac, av, start);

	return (ret);
}
