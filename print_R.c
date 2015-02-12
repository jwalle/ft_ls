/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_R.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 14:50:53 by jwalle            #+#    #+#             */
/*   Updated: 2015/02/09 18:18:33 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
/*
void	stock_R(char **av, t_static2 *opt)
{
	DIR				*dir;
	struct dirent   *dp;
	struct stat		fileStat;
	char			*path;
	int				j;
	

	// je dois parse avant si plusieurs **av...
	//while((dp = readdir(dir)) != NULL)
	j = 0;
	while(av[j])
	{
		dir = opendir(av);
		while(dp = readdir(dir))
		{
			 path = correct_path(av[j], dp->d_name);
			 stat(path, &fileStat);
			if (fileStat.st_mode && S_ISDIR)
				
		}
		//stock_R(str);
	}
	opt->R = 0;
}
*/

void	ft_print_R(char *av, t_static2 *opt, ll_list *cur)
{
	char	*path;

	while(cur)
	{
		if (cur->filename[0] != '.' || opt->a)
		{
			if (cur->isdir && ft_strcmp(cur->filename, ".") && ft_strcmp(cur->filename, ".."))
			{
				path = correct_path(av, cur->filename);
				cur = cur->next;
				choose_prog(opt, path);
			}
			else
				cur = cur->next;
		}
		else
			cur = cur->next;
	}
}
