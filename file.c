/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 17:34:36 by jwalle            #+#    #+#             */
/*   Updated: 2015/01/26 15:14:31 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


ll_list		*fail_open_directory(char *str)
{
	DIR				*dir;
	struct stat		fileStat;
	ll_list			*head;

	head = NULL;
	dir = opendir(str);
	if (dir == NULL && stat(str, &fileStat))
	{
		ft_putstr("ft_ls: cannot access ");
		ft_putstr(str);
		ft_putstr(": No such file or directory\n");
		return(NULL);
	}
	else
	{
		head = ll_copy_new_file(str, head, fileStat);
		return (head);
	}
	return (NULL);
}

void		close_directory(DIR *dir)
{
	(void)closedir(dir);
}

char	*correct_path(char *s1, char *s2)
{
	char	*str;
	
	str = ft_strdup(s1);
	str = ft_strjoin(str, "/");
	str = ft_strjoin(str, s2);

	return (str);
}

ll_list    *ll_copy_new_file(char *str, ll_list *head, struct stat fileStat)
{
    ll_list *new;

    new = (ll_list*)malloc(sizeof(ll_list));
    new->next = head;
    head = new;
    new->filename = ft_strdup(str);
    get_info_file(new, fileStat);
    return (new);
}

void	get_info_file(ll_list *current, struct stat fileStat)
{
	struct passwd	*pwd;
	struct group	*grp;

	get_permission(fileStat, current);
	current->isdir = S_ISDIR(fileStat.st_mode);
	current->link = fileStat.st_nlink;
	pwd = getpwuid(fileStat.st_uid);
	current->uid = ft_strdup(pwd->pw_name);
	current->uid_nb = fileStat.st_uid;
	grp = getgrgid(fileStat.st_gid);
	current->gid = ft_strdup(grp->gr_name);
	current->gid_nb = fileStat.st_gid;
	current->size = fileStat.st_size;
	current->bsize = fileStat.st_blocks / 2;
	current->time = fileStat.st_mtime;
}