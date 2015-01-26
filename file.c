/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 17:34:36 by jwalle            #+#    #+#             */
/*   Updated: 2014/12/13 18:23:51 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	fail_open_directory(char *str)
{
	DIR		*dir;
	
	dir = opendir(str);
	if (dir == NULL)
	{
		ft_putstr("ft_ls: cannot access ");
		ft_putstr(str);
		ft_putstr(": No such file or directory\n");
		//return (NULL);
	}
	//printf("placeholder open directory\n");
	//return (dir);
}

/*struct dirent	*get_content(DIR *dir)
{
	struct dirent	*dp;
	
	dp = readdir(dir);
	//printf("placeholder get_content\n");
	return (dp);
}*/

void		close_directory(DIR *dir)
{
	(void)closedir(dir);
}

int		can_open(struct dirent *dp, char *str)
{
	struct stat fileStat;
	char	*path;

	path = correct_path(str, dp->d_name);
	stat(path, &fileStat);
	if (S_ISDIR(fileStat.st_mode) == 1)
		return (1);
	return (0);
}

char	*correct_path(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;
	
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = ft_strnew(i + j + 1);
	ft_strcpy(str, s1);
	if (s1[i] != '/')
		ft_strcat(str, "/");
	ft_strcat(str, s2);
	return (str);
	printf("plop2\n");
}