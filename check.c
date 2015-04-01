/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 17:31:11 by jwalle            #+#    #+#             */
/*   Updated: 2015/03/31 15:54:15 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		error(char c)
{
	if (c != 'l' && c != 'R' && c != 'a' && c != 'r' && c != 't'
	&& c != 'A' && c != 'd' && c != 'g' && c != 'G' && c != 'i'
	&& c != 'n' && c != 'S' && c != 'v' && c != 's' && c != '1' && c != '-')
	{
		ft_putstr("ft_ls: illegal option -- '");
		ft_putchar(c);
		ft_putstr("'\n");
		ft_putstr("usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] ");
		ft_putstr("[file ...]\n");
		return (1);
	}
	else
		return (0);
	return (1);
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
	while (av[i])s
	{
		if (av[i] == 't')
			opt->sort = 't';
		if (av[i] == 'S')
			opt->sort = 'S';
		i++;
	}
	return (1);
}

int		choose_prog(t_static2 *opt, char *av)
{
	ll_list		*cur;

	cur = ll_stock(av);
	merge_sort(&cur, opt);
	if (cur)
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
			//free_all(cur);
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
		free_all(cur);
	}
	return (1);
}
