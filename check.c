/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 17:31:11 by jwalle            #+#    #+#             */
/*   Updated: 2014/12/13 18:23:36 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		error(char c)
{
	if (c != 'l' || c != 'R' || c != 'a' || c != 'r' || c != 't'
	|| c != 'A' || c != 'd' || c != 'g' || c != 'G' || c != 'i'
	|| c != 'n' || c != 'S' || c != 'v')
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

int		options(char *av)
{
	int i;
	static t_static2 opt;
	
	i = 1;
	if (av[0] != '-')
		return (main(2, av));
	while (av[i])
	{
		if (av[i] == 'l')
			opt.l = 1;
		if (av[i] == 'R')
			opt.R = 1;
		if (av[i] == 'a')
			opt.a = 1;
		if (av[i] == 'r')
			opt.r = 1;
		if (av[i] == 't')
			opt.t = 1;
		if (av[i] == 'A')
			opt.A = 1;
		i++;
	}
	return (options2(av, opt));
}

int		options2(char *av, t_static2 opt)
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
			opt.error = 1;
		i++;
	}
	return (1);
}

int		choose_prog(void)
{
	printf("placeholder choose program to run\n");
	return (1);
}