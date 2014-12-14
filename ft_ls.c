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
#define BOLD "\033[1m"

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


void	ft_ls(char *str, t_static2 *opt)
{
	DIR				*dir;
	struct dirent	*dp;
//	struct stat		fileStat;
//	int 			i;
	
	//printf("plop");
	dir = opendir(str);
	if (dir == NULL)
		open_directory(str);
	while ((dp = readdir(dir)))
	{
		if (dp->d_name[0] == '.')
		{
			if (can_open(dp)  && opt->a)
				printf(BOLD "%s" RESET, dp->d_name);
			if (!can_open(dp) && opt->a)
				ft_putstr(dp->d_name);
		}
		else
		{
			if (can_open(dp))
				printf(BOLD "%s" RESET, dp->d_name);
			else
				ft_putstr(dp->d_name);
		}
		ft_putstr(" ");
	}
	ft_putchar('\n');
	close_directory(dir);
}

int		main(int ac, char **av)
{
	int i;
	static t_static2 opt;
	i = 1;
	//printf("ac = %d\n", ac);
	if (ac == 1)
		ft_ls(".", &opt);
	if (ac == 2)
		options(av[1], &opt);
	if (ac > 2)
	{
		while (av[i])
		{
			if (i == 1)
			{
				options(av[i], &opt);
				i++;
			}
			//printf("av = %s\n",av[i]);
			ft_ls(av[i], &opt); // les options peuvent aller etre rentre apres le(s) dossier(s)...
			i++;
		}
	}
	return (0);
}
