/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 08:48:45 by jwalle            #+#    #+#             */
/*   Updated: 2014/12/13 18:22:57 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#define RESET "\033[0m"
#define BOLD "\e[1m"

int		can_open(struct dirent *dp)
{
	struct stat fileStat;
	//char		filename[512];

	//filename = dp->d_name;
	lstat(dp->d_name, &fileStat);
	if(S_ISDIR(fileStat.st_mode) == 1)
		return (1);
	return (0);
}


void	ft_ls(char *str)
{
	struct dirent	*dp;
//	struct stat		fileStat;
	DIR				*dir;
	//int				i;

	dir = opendir(str);
	if (dir == NULL)
		printf("Open error");
	while ((dp = readdir(dir)))
	{
		if (dp->d_name[0] != '.')
		{
			if (can_open(dp))
				printf(BOLD "%s\n" RESET, dp->d_name);
			else
				puts(dp->d_name);
		}
	}
	(void)closedir(dir);
}

int		main(int ac, char **av)
{
	int i;
	
	i = 1;
	if (ac == 2)
		ft_ls("./test/");
	if (ac == 3)
		options(av[1]);
	if (ac > 3)
	{
		while (av[i])
		{
			main(2, av[i]);
			i++;
		}
	}
	return (0);
}
