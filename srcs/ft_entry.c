/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:39:24 by msteffen          #+#    #+#             */
/*   Updated: 2018/03/05 17:54:57 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_entry.h"
#include <errno.h>

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
	entry->link_name = NULL;
	entry->subentries = NULL;

	entry->s_isreg = 0;
	entry->s_isdir = 0;
	entry->s_islnk = 0;

	return (entry);
}

void 		destroy_entry(t_entry **entry)
{
	// @todo check s'il faut free les char*
	if (*entry == NULL)
		return ;
	if ((*entry)->name != NULL)
		free((*entry)->name);
	free((*entry)->user);
	free((*entry)->group);
	if ((*entry)->link_name != NULL)
		free((*entry)->link_name);
	free(*entry);
	*entry = NULL;
}

t_entry 	*ft_parse_file_entry(char *fullpath, char *filename)
{
	struct stat stated;
	t_entry		*entry;

	struct passwd 	*pw;
	struct group	*gr;

	if (lstat(fullpath, &stated) != 0)
		return (NULL);
	entry = create_entry();

	entry->s_isreg = S_ISREG(stated.st_mode);
	entry->s_isdir = S_ISDIR(stated.st_mode);
	entry->s_islnk = S_ISLNK(stated.st_mode);

	if (filename == NULL)
		entry->name = ft_strdup(fullpath);
	else
		entry->name = ft_strdup(filename);







	if (S_ISREG(stated.st_mode))
		entry->type = '-';
	if (S_ISDIR(stated.st_mode))
		entry->type = 'd';
	if (S_ISLNK(stated.st_mode))
	{
		entry->type = 'l';
		entry->link_name = ft_strnew(128);
		readlink(fullpath, entry->link_name, 128);
	}


	// CHMOD

	(void)filename;

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




	// User / group

	pw = getpwuid(stated.st_uid);
	gr = getgrgid(stated.st_gid);
	if (pw == NULL || gr == NULL)
	{
		ft_printf("ERR %d %s \n", errno, strerror(errno));
	}
	else
	{
		entry->user = ft_strdup(pw->pw_name);
		entry->group = ft_strdup(gr->gr_name);
	}


	// Date
	entry->last_edit_date = ft_strdup(ctime(&stated.st_mtime) + 4);


	// Nb links
	entry->nb_links = stated.st_nlink;

	// size
	entry->sz_bytes = stated.st_size;
	entry->sz_blocks = stated.st_blocks;



	return (entry);
}
