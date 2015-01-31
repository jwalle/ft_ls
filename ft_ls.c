/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 08:48:45 by jwalle            #+#    #+#             */
/*   Updated: 2015/01/29 16:47:27 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls(t_static2 *opt, ll_list *cur)
{
	while (cur != NULL)
	{
		if (cur->filename[0] != '.' || opt->a)
		{
			if (cur->filename[0] == '.')
				((cur->isdir) && opt->a) ? ft_putstr_b(cur->filename) 
											: ft_putstr(cur->filename);
			else
				(cur->isdir) ? ft_putstr_b(cur->filename)
								: ft_putstr(cur->filename);
			ft_putstr(" ");
		}
		cur = cur->next;
	}
	ft_putchar('\n');
}

void	ft_parse(char **av, t_static2 *opt)
{
	char 	**str;
	int		i;
	int 	j;
	DIR		*dir;

	i = -1;
	j = 0;
	str = malloc(sizeof(*str) * 512);
	opt->dft = 1;
	while (av[++j])
	{
		if(av[j][0] ==  '-')
		{
			options(av[j], opt);
			opt->dft = 0;
		}
		else if (av[j][0] != '-' && (dir = opendir(av[j])) == NULL)
			fail_open_directory(av[j]); //devrait marcher si av est un nom de fichier...
		else
			str[++i] = ft_strdup(av[j]);
	}
	j = -1;
	while (str[++j])
		print_parsed(str[j], opt);
}

int		main(int ac, char **av)
{
	static t_static2 opt;
	
	opt.sort = 'd';
	if (ac == 1)
	{
		opt.dft = 1;
		choose_prog(&opt, ".");
	}
	if (ac == 2)
	{
		//ft_parse(av, &opt);
		if(av[1][0] == '-')
		{
			options(av[1], &opt);
			choose_prog(&opt, ".");
		}
		else
			choose_prog(&opt, av[1]);
	}
	if (ac > 2)
		ft_parse(av, &opt);
	return (0);
}
