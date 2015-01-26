/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 08:48:45 by jwalle            #+#    #+#             */
/*   Updated: 2015/01/26 17:28:56 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls(char *str, t_static2 *opt)
{
	ll_list   		*cur;

	cur = ll_stock(str);
	merge_sort(&cur);
	while (cur != NULL)
	{
		if (cur->filename[0] == '.')
			((cur->isdir) && opt->a) ? ft_putstr_b(cur->filename) : ft_putstr(cur->filename);
		else
			(cur->isdir) ? ft_putstr_b(cur->filename) : ft_putstr(cur->filename);
		ft_putstr(" ");
		cur = cur->next;
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
			ft_ls(av[i], &opt); // les options peuvent etre rentre apres le(s) dossier(s)...
			i++;
		}
	}
	return (0);
}

// 
