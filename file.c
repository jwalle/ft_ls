/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 17:34:36 by jwalle            #+#    #+#             */
/*   Updated: 2015/03/06 16:45:12 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

ll_list		*fail_open_directory(char *str)
{
	DIR				*dir;
	struct stat		filestat;
	ll_list			*head;

	head = NULL;
	dir = opendir(str);
	if (dir == NULL && stat(str, &filestat))
	{
		ft_putstr("ft_ls: cannot access ");
		ft_putstr(str);
		ft_putstr(": No such file or directory\n");
		return (NULL);
	}
	else
	{
		head = ll_copy_new_file(str, head, filestat);
		return (head);
	}
	return (NULL);
}

void		close_directory(DIR *dir)
{
	(void)closedir(dir);
}

char		*correct_path(char *s1, char *s2)
{
	char	*str;

	if (strcmp(s1, "/dev"))
	{
		str = ft_strdup(s1);
		str = ft_strjoin(str, "/");
		str = ft_strjoin(str, s2);
		return (str);
	}
	if (strcmp(s1, "/dev/"))
	{
		str = ft_strdup(s1);
		str = ft_strjoin(str, s2);
		return (str);
	}
	return (s1);
}

ll_list		*ll_copy_new_file(char *str, ll_list *head, struct stat filestat)
{
	ll_list	*new;

	new = (ll_list*)malloc(sizeof(ll_list));
	new->next = head;
	head = new;
	new->filename = ft_strdup(str);
	get_info_file(new, filestat);
	return (new);
}

void		get_info_file(ll_list *current, struct stat filestat)
{
	struct passwd	*pwd;
	struct group	*grp;

	get_permission(filestat, current);
	current->isdir = S_ISDIR(filestat.st_mode);
	current->link = filestat.st_nlink;
	pwd = getpwuid(filestat.st_uid);
	current->uid = ft_strdup(pwd->pw_name);
	current->uid_nb = filestat.st_uid;
	grp = getgrgid(filestat.st_gid);
	current->gid = ft_strdup(grp->gr_name);
	current->gid_nb = filestat.st_gid;
	current->size = filestat.st_size;
	current->bsize = filestat.st_blocks / 2;
	current->time = filestat.st_mtime;
}
