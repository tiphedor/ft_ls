/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 14:43:44 by msteffen          #+#    #+#             */
/*   Updated: 2018/02/27 21:45:22 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_entry.h"
#include<stdio.h>
#include <time.h>

#include <pwd.h>
#include <grp.h>
#include <sys/stat.h>
#include <errno.h>
t_entry 	*create_entry_file(char *path)
{
	struct stat stated;
	struct passwd *pw;
	struct group  *gr;
	char 	*lnk_target;
	int 	lnk_len;
	t_entry *entry;


	lstat(path, &stated);
	entry = create_entry();


	// Type

	if (S_ISREG(stated.st_mode))
		entry->type = '-';
	if (S_ISDIR(stated.st_mode))
		entry->type = 'd';
	if (S_ISLNK(stated.st_mode))
	{
		entry->type = 'l';
		lnk_target = ft_strnew(128);
		lnk_len = readlink(path, lnk_target, 128);
		lnk_target[lnk_len] = '\0';
	}


	// CHMOD

	entry->o_r = (stated.st_mode & S_IRUSR) ? 1 : 0;
	entry->o_w = (stated.st_mode & S_IWUSR) ? 1 : 0;
	entry->o_x = (stated.st_mode & S_IXUSR) ? 1 : 0;
	entry->g_r = (stated.st_mode & S_IRGRP) ? 1 : 0;
	entry->g_w = (stated.st_mode & S_IWGRP) ? 1 : 0;
	entry->g_x = (stated.st_mode & S_IXGRP) ? 1 : 0;
	entry->w_r = (stated.st_mode & S_IROTH) ? 1 : 0;
	entry->w_w = (stated.st_mode & S_IWOTH) ? 1 : 0;
	entry->w_x = (stated.st_mode & S_IXOTH) ? 1 : 0;


	// int 		nb_links;
	// char		*user;
	// char		*group;
	// int 		bytes;
	// int 		last_edit_date;


	// Name

	if (S_ISLNK(stated.st_mode))
	{
		entry->name = ft_strnew(ft_strlen(path) + ft_strlen(lnk_target) + 5);
		ft_strcpy(entry->name, path);
		ft_strcat(entry->name, " -> ");
		ft_strcat(entry->name, lnk_target);
	}
	else
	{
		entry->name = ft_strdup(path);
	}


	// User / group

	pw = getpwuid(stated.st_uid);
	gr = getgrgid(stated.st_gid);
	if (pw == NULL || gr == NULL)
	{
		printf("ERR %d %s \n", errno, strerror(errno));
	}
	entry->user = ft_strdup(pw->pw_name);
	entry->group = ft_strdup(gr->gr_name);

	// Date
	entry->last_edit_date = ft_strdup(ctime(&stated.st_mtime) + 4);


	// Nb links
	entry->nb_links = stated.st_nlink;

	// size
	entry->sz_bytes = stated.st_size;
	entry->sz_blocks = stated.st_blocks;



	return (entry);
}

t_entry 	*create_entry()
{
	t_entry *entry;

	if ((entry = (t_entry*)malloc(sizeof(t_entry))) == NULL)
		return (NULL);
	entry->type = '#';
	entry->nb_links = 0;
	entry->user = NULL;
	entry->group = NULL;
	entry->name = NULL;
	entry->sz_bytes = 0;
	entry->last_edit_date = 0;
	entry->o_r = 0;
	entry->o_w = 0;
	entry->o_x = 0;
	entry->g_r = 0;
	entry->g_w = 0;
	entry->g_x = 0;
	entry->w_r = 0;
	entry->w_w = 0;
	entry->w_x = 0;
	entry->sz_blocks = 0;
	return (entry);
}

void 		destroy_entry(t_entry **entry)
{
	// @todo check s'il faut free les char*
	free((*entry)->name);
	free((*entry)->user);
	free((*entry)->group);
	free(*entry);
	*entry = NULL;
}
