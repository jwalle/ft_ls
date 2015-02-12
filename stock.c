/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 17:46:15 by jwalle            #+#    #+#             */
/*   Updated: 2015/02/09 18:23:03 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

ll_list     *ll_stock(char *str, t_static2 *opt)
{
    ll_list         *head;
    ll_list         *current;
    DIR             *dir;
    struct dirent   *dp;

    head = NULL;
    current = head;
    if ((dir = opendir(str)) == NULL)
    {
        fail_open_directory(str);
        return (NULL);
    }
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
	if (opt->A)
		printf("plop1 stock\n");
    return (head);
}

ll_list    *ll_copy_new(char *str, struct dirent *dp, ll_list *head, char *str2)
{
    ll_list *new;

    new = (ll_list*)malloc(sizeof(ll_list));
    new->next = head;
    head = new;
    new->filename = ft_strdup(str);
    get_info(dp, new, str2);
    return (new);
}

ll_list    *ll_copy_cur(char *str, struct dirent *dp, ll_list *cur, char *str2)
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
	struct stat		fileStat;
	struct passwd	*pwd;
	struct group	*grp;
	char			*path;

	path = correct_path(str, dp->d_name);
	stat(path, &fileStat);
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

	//printf("%s, %d, %s\n", current->uid, current->size, ctime(&current->time));
	//printf("time 1 : %s\n", ctime(current->time)); // verifier que les id sont bons.
}

void	get_permission(struct stat fileStat, ll_list *current)
{
	char *str;

	str = ft_strnew(10);	
	str[0] = file_type(fileStat);
	str[1] = (fileStat.st_mode & S_IRUSR) ? 'r' : '-';
	str[2] = (fileStat.st_mode & S_IWUSR) ? 'w' : '-';
	str[3] = (fileStat.st_mode & S_IXUSR) ? 'x' : '-';
	str[4] = (fileStat.st_mode & S_IRGRP) ? 'r' : '-';
	str[5] = (fileStat.st_mode & S_IWGRP) ? 'w' : '-';
	str[6] = (fileStat.st_mode & S_IXGRP) ? 'x' : '-';
	str[7] = (fileStat.st_mode & S_IROTH) ? 'r' : '-';
	str[8] = (fileStat.st_mode & S_IWOTH) ? 'w' : '-';
	str[9] = (fileStat.st_mode & S_IXOTH) ? 'x' : '-';
	current->perm = ft_strdup(str);
	free(str);
}

char	file_type(struct stat fileStat)
{
	char c;

	if (S_ISDIR(fileStat.st_mode))
		c = 'd';
	else if (S_ISBLK(fileStat.st_mode))
		c = 'b';
	else if (S_ISCHR(fileStat.st_mode))
		c = 'c';
	else if (S_ISLNK(fileStat.st_mode))
		c = 'l';
	else if (S_ISFIFO(fileStat.st_mode))
		c = 'p';
	else
		c = '-';
	return (c);
}