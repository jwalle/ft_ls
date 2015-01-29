/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 17:31:11 by jwalle            #+#    #+#             */
/*   Updated: 2015/01/29 16:25:14 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		error(char c)
{
	//printf("c = %c\n", c);
	if (c != 'l' && c != 'R' && c != 'a' && c != 'r' && c != 't'
	&& c != 'A' && c != 'd' && c != 'g' && c != 'G' && c != 'i'
	&& c != 'n' && c != 'S' && c != 'v')
	{
		ft_putstr("ft_ls: invalid option -- '");
		ft_putchar(c);
		ft_putstr("'\n");
		ft_putstr("Try 'ls --help for more information.\n");
		return (1);
	}
	else
		return(0);
	return (1);
}

void		options(char *av, t_static2 *opt)
{
	int i;
	
	//printf("option\n");
	i = 1;
	/*if ((av[0] != '-') || (av[0] == '-' && !av[1]))
	{
		ft_ls(opt);
		return ;
	}*/
	while (av[i])
	{
		if (av[i] == 'l')
			opt->l = 1;
		if (av[i] == 'R')
			opt->R = 1;
		if (av[i] == 'a')
			opt->a = 1;
		if (av[i] == 'r')
			opt->r = 1;
		if (av[i] == 't')
			opt->t = 1;
		if (av[i] == 'A')
			opt->A = 1;
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
		if (av[i] == 'S')
			opt->S = 1;
		if (av[i] == 'v')
			opt->v = 1;
		if (error(av[i]))
			return;
		i++;
	}
}

int		choose_prog(t_static2 *opt, char *av)
{
	ll_list		*cur;
	
	cur = ll_stock(av, opt);
	merge_sort(&cur);
	if (opt->dft)
		ft_ls(opt, cur);
	if (opt->l)
	{
		print_l(cur, opt);
		return(1);
	}
	if (opt->R)
		printf("Option r.%s\n", av);
	printf("placeholder choose program to run\n");
	free(cur);
	return (1);
}
