/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 17:31:11 by jwalle            #+#    #+#             */
/*   Updated: 2015/02/09 18:57:15 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		error(char c)
{
	//printf("c = %c\n", c);
	if (c != 'l' && c != 'R' && c != 'a' && c != 'r' && c != 't'
	&& c != 'A' && c != 'd' && c != 'g' && c != 'G' && c != 'i'
	&& c != 'n' && c != 'S' && c != 'v' && c != 's')
	{
		ft_putstr("ft_ls: illegal option -- '");
		ft_putchar(c);
		ft_putstr("'\n");
		ft_putstr("usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n");
		//ft_putstr("Try 'ls --help for more information.\n");
		return (1);
	}
	else
		return(0);
	return (1);
}

void		options(char *av, t_static2 *opt)
{
	int i;
	
	i = 1;
	opt->no_r = 1;
	while (av[i])
	{
		if (error(av[i])) //DOIT QUITTER LE PROGRAMME
			return;
		if (av[i] == 'l')
			opt->l = 1;
		if (av[i] == 'a')
			opt->a = 1;
		if (av[i] == 'r')
		{
			opt->r = 1;
			opt->no_r = 0;
		}
		if (av[i] == 't')
			opt->sort = 't';
		if (av[i] == 'S')
			opt->sort = 'S';
		if (av[i] == 's')
			opt->s = 1;
		if (av[i] == 'R')
			opt->R = 1;
		i++;
	}
	options2(av, opt);
}

void		options2(char *av, t_static2 *opt)
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
}

int		choose_prog(t_static2 *opt, char *av)
{
	ll_list		*cur;
	//char		**str;
	
	//str = malloc(sizeof(*str) * 512);
	
		//printf("Option r.%s\n", av);
	//printf("placeholder choose program to run\n");
	cur = ll_stock(av, opt);
	merge_sort(&cur, opt);
	if (opt->R)
	{
		//printf("plop choose\n");
		ft_ls(opt, cur);
		ft_print_R(av, opt, cur);
	}
	else if (opt->dft)
		ft_ls(opt, cur);
	else if (opt->l)
	{
		print_l(cur, opt);
		return(1);
	}
	else
		ft_ls(opt, cur);
	free(cur);
	return (1);
}
