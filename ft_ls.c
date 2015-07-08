/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 08:48:45 by jwalle            #+#    #+#             */
/*   Updated: 2015/05/27 18:52:49 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls(t_static2 *opt, ll_list *list)
{
	ll_list *cur;

	cur = list;
	while (cur != NULL)
	{
		if (cur->filename[0] != '.' || opt->a)
		{
			if (opt->s)
				ft_putnnbr(0, cur->bsize);
			if (cur->filename[0] == '.')
				((cur->isdir) && opt->a) ? ft_putstr_b(cur->filename)
											: ft_putstr(cur->filename);
			else
				(cur->isdir) ? ft_putstr_b(cur->filename)
								: ft_putstr(cur->filename);
			ft_putstr("\n");
		}
		cur = cur->next;
	}
	free_all(list);
}

void destroy_parse(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_parse(char **av, t_static2 *opt)
{
	char	**str;
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	str = malloc(sizeof(*str) * 512);
	while (av[++j])
	{
		k = is_opt(av[j]);
		if (k != 0)
		{
			if (k == 1)
			{
				if (options(av[j], opt) == 0)
					return ;
			}
		}
		else
			str[++i] = ft_strdup(av[j]);
	}
	j = -1;
	while (str[++j])
		print_parsed(str[j], opt, i--);
	destroy_parse(str);
}

int		main(int ac, char **av)
{
	static t_static2 opt;

	opt.sort = 'd';
	if (ac == 1)
		choose_prog(&opt, ".");
	if (ac == 2)
	{
		if (!ft_strcmp(av[1], "-1"))
			av++;
		if (is_opt(av[1]))
		{
			if (options(av[1], &opt) == 0)
				return (0);
			choose_prog(&opt, ".");
		}
		else
			choose_prog(&opt, av[1]);
	}
	if (ac > 2)
		ft_parse(av, &opt);
	return (0);
}
