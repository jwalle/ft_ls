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
				((cur->isdir) && opt->a) ? ft_putstr_b(cur->filename) : ft_putstr(cur->filename);
			else
				(cur->isdir) ? ft_putstr_b(cur->filename) : ft_putstr(cur->filename);
			ft_putstr("\t");
		}
		cur = cur->next;
	}
	ft_putchar('\n');
}

void	ft_parse(char **av, t_static2 *opt, int ac)
{
	char 	**str;
	int		i;
	int 	j;

	i = -1;
	j = 0;
	str = malloc(sizeof(*str) * ac);
	opt->dft = 1;
	while (ac > ++j)
	{
		if(av[j][0] ==  '-')
		{
			options(av[j], opt);
			opt->dft = 0;
		}
		else
		{
			str[++i] = ft_strnew(ft_strlen(av[j]));
			ft_strcpy(str[i], av[j]);
		}
	}
	j = 0;
	while (str[j])
	{
		ft_putstr(str[j]);
		ft_putstr(":\n");
		choose_prog(opt, str[j]);
		ft_putchar('\n');
		j++;
	}
}

int		main(int ac, char **av)
{
	static t_static2 opt;
	
	if (ac == 1)
	{
		opt.dft = 1;
		choose_prog(&opt, ".");
	}
	if (ac == 2)
	{
		options(av[1], &opt);
		choose_prog(&opt, av[1]);
	}
	if (ac > 2)
	{
		ft_parse(av, &opt, ac);
	}
	return (0);
}
