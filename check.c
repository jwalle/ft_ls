/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 17:31:11 by jwalle            #+#    #+#             */
/*   Updated: 2015/05/23 20:40:52 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		error(char c)
{
	char *str;

	str = "l,R,a,r,t,A,d,g,G,i,n,S,v,s,1,-";
	if (!strchr(str, c))
	{
		ft_putstr("ft_ls: illegal option -- '");
		ft_putchar(c);
		ft_putstr("'\n");
		ft_putstr("usage: ls [-lRartAdgGinSvs1-] ");
		ft_putstr("[file ...]\n");
		return (1);
	}
	return (0);
}

int		options(char *av, t_static2 *opt)
{
	int i;

	i = 1;
	opt->no_r = 1;
	while (av[i])
	{
		if (error(av[i]))
			return (0);
		if (av[i] == 'l' || av[i] == 'G' || av[i] == 'g' || av[i] == 'n')
			opt->l = 1;
		if (av[i] == 'a')
			opt->a = 1;
		if (av[i] == 'r')
		{
			opt->r = 1;
			opt->no_r = 0;
		}
		if (av[i] == 's')
			opt->s = 1;
		if (av[i] == 'R')
			opt->R = 1;
		i++;
	}
	return (options2(av, opt));
}

int		options2(char *av, t_static2 *opt)
{
	int i;

	i = 1;
	while (av[i])
	{
		if (av[i] == 'd')
			opt->d = 1;
		if (av[i] == 'g')
			opt->g = 1;
		if (av[i] == 'G')
			opt->G = 1;
		if (av[i] == 'i')
			opt->i = 1;
		if (av[i] == 'n')
			opt->n = 1;
		if (av[i] == 'v')
			opt->v = 1;
		if (av[i] == 'A')
			opt->A = 1;
		i++;
	}
	return (options3(av, opt));
}

int		options3(char *av, t_static2 *opt)
{
	int i;

	i = 1;
	while (av[i])
	{
		if (av[i] == 't')
			opt->sort = 't';
		if (av[i] == 'S')
			opt->sort = 'S';
		if (av[i] == '-')
			opt->end = 1;
		i++;
	}
	return (1);
}

int		check_perm(ll_list *cur)
{
	DIR	*dir;

	dir = NULL;
	if (cur->perm[0] == 'd' && (dir = opendir(cur->filename)) == NULL)
	{
		ft_putstr("ls: ");
		ft_putstr(cur->filename);
		ft_putstr(": Permission denied\n");
		//printf("gid : %s, uid : %s, perm : %s", cur->gid, cur->uid, cur->perm);
		return (0);
	}
	else if (dir)
		close_directory(dir);
	return (1);
}

int		choose_prog(t_static2 *opt, char *av)
{
	ll_list		*cur;

	cur = ll_stock(av);
	merge_sort(&cur, opt);
	if (cur && check_perm(cur))
	{
		if (opt->R)
		{
			print_folder(av);
			if (opt->l)
				print_l(cur, opt);
			else
				ft_ls(opt, cur);
			ft_putchar('\n');
			ft_print_r(av, opt, cur);
		}
		else if (opt->l)
		{
			if(ft_strcmp(av, "/dev/") == 0)
				print_dev(cur, opt);
			else
				print_l(cur, opt);
		}
		else
			ft_ls(opt, cur);
	}
	free_all(cur);
	return (1);
}
