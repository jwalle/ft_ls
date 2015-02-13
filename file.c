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


void	*fail_open_directory(char *str)
{
	DIR		*dir;
	
	dir = opendir(str);
	if (dir == NULL)
	{
		ft_putstr("ft_ls: cannot access ");
		ft_putstr(str);
		ft_putstr(": No such file or directory\n");
		return(NULL);
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
