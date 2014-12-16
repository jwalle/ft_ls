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
#define ANSI_COLOR_RED     "\x1b[31m"

int		can_open(struct dirent *dp)
{
	struct stat fileStat;
	
	stat(dp->d_name, &fileStat);
	if (S_ISDIR(fileStat.st_mode) == 1)
		return (1);
	return (0);
}

void	ft_putstr_bold(char *str)
{
	ft_putstr(ANSI_COLOR_RED);
	ft_putstr(str);
	ft_putstr(RESET);
}

void	ft_ls(char *str, t_static2 *opt)
{
	ll_list   		*current;

	current = ll_stock(str);
	while (current != NULL)
	{
		if (current->filename[0] == '.')
		{
			if ((current->isdir) && opt->a)
				ft_putstr_bold(current->filename);
			if (!(current->isdir) && opt->a)
				ft_putstr(current->filename);
		}
		else
		{
			if ((current->isdir))
				ft_putstr_bold(current->filename);
			else
				ft_putstr(current->filename);
		}
		ft_putstr(" ");
		current = current->next;
	}
	ft_putchar('\n');
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
