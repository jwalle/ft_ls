/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 18:00:35 by jwalle            #+#    #+#             */
/*   Updated: 2015/07/09 18:00:50 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


void choose_prog2(char *av, t_static2 *opt)
{
	ll_list		*list;

	list = ll_stock(av);
	merg
	if (list)
	{

	}


}

void ft_parse(char **av, t_static2 *opt)
{
	int 	i;

	i = 0;
	if (av)
	{
		if (av[0] == '-' && !opt->end)
		{
			options(av, opt);
		}
		else
		{
			choose_prog2(opt, av);
		}
	}
	ft_parse(++av, opt);
}

int main(int ac, char **av)
{
	t_static2 *opt;

	ft_parse(++av, opt);
	return(0);
}
