/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 17:46:15 by jwalle            #+#    #+#             */
/*   Updated: 2015/03/31 18:17:51 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

ll_list	*ll_stock(char *str)
{
	ll_list			*head;
	ll_list			*current;
	DIR				*dir;
	struct dirent	*dp;

	head = NULL;
	current = head;
	if ((dir = opendir(str)) == NULL)
		return (fail_open_directory(str));
	while ((dp = readdir(dir)))
	{
		if (head == NULL)
		{
			head = ll_copy_new(dp->d_name, dp, head, str);
			current = head;
		}
		else
		{
			while (current->next != NULL)
				current = current->next;
			current = ll_copy_cur(dp->d_name, dp, current, str);
		}
	}
	close_directory(dir);
	return (head);
}

ll_list	*ll_copy_new(char *str, struct dirent *dp, ll_list *head, char *str2)
{
	ll_list *new;

	new = (ll_list*)malloc(sizeof(ll_list));
	new->next = head;
	head = new;
	new->filename = ft_strdup(str);
	get_info(dp, new, str2);
	return (new);
}

ll_list	*ll_copy_cur(char *str, struct dirent *dp, ll_list *cur, char *str2)
{
	ll_list *new;

	new = (ll_list*)malloc(sizeof(ll_list));
	cur->next = new;
	new->next = NULL;
	new->filename = ft_strdup(str);
	get_info(dp, new, str2);
	return (new);
}

void	get_info(struct dirent *dp, ll_list *current, char *str)
{
	struct stat		filestat;
	struct passwd	*pwd;
	struct group	*grp;
	char			*path;
	char			*temp;
	ssize_t				r;

	temp = ft_strnew(256);
	path = correct_path(str, dp->d_name);
	//printf("str = %s, path = %s\n", str, path);
	lstat(path, &filestat);
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
	current->device = filestat.st_rdev;
	min_maj(current);
	if (S_ISLNK(filestat.st_mode))
	{
		current->islink = 1;
		r = readlink(path, temp, sizeof(temp) - 1);
		temp[r] = 0;
		current->link_path = ft_strdup(temp);
	}
	else
		current->islink = 0;
	free(temp);
	free(path);
}

void	get_permission(struct stat filestat, ll_list *current)
{
	char *str;

	str = ft_strnew(11);
	str[0] = file_type(filestat);
	str[1] = (filestat.st_mode & S_IRUSR) ? 'r' : '-';
	str[2] = (filestat.st_mode & S_IWUSR) ? 'w' : '-';
	str[3] = (filestat.st_mode & S_IXUSR) ? 'x' : '-';
	str[4] = (filestat.st_mode & S_IRGRP) ? 'r' : '-';
	str[5] = (filestat.st_mode & S_IWGRP) ? 'w' : '-';
	str[6] = (filestat.st_mode & S_IXGRP) ? 'x' : '-';
	str[7] = (filestat.st_mode & S_IROTH) ? 'r' : '-';
	str[8] = (filestat.st_mode & S_IWOTH) ? 'w' : '-';
	str[9] = (filestat.st_mode & S_IXOTH) ? 'x' : '-';
	str[10] = 0;
	current->perm = ft_strdup(str);
	free(str);
}

char	file_type(struct stat filestat)
{
	char c;

	if (S_ISDIR(filestat.st_mode))
		c = 'd';
	else if (S_ISBLK(filestat.st_mode))
		c = 'b';
	else if (S_ISCHR(filestat.st_mode))
		c = 'c';
	else if (S_ISLNK(filestat.st_mode))
		c = 'l';
	else if (S_ISFIFO(filestat.st_mode))
		c = 'p';
	else if (S_ISSOCK(filestat.st_mode))
		c = 's';
	else
		c = '-';
	return (c);
}

void	min_maj(ll_list *current)
{
	//current->major = 0;
	//current->minor = 0;
	current->major = major(current->device);
	current->minor = minor(current->device);
}

