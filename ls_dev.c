/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_dev.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 17:54:27 by jwalle            #+#    #+#             */
/*   Updated: 2015/03/17 17:26:53 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_putdevstr(int max, char *str)
{
	int i;

	i = 0;
	ft_putstr(str);
	while ((int)(ft_strlen(str) + i) < max)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putstr(" ");
}

void	ft_putdevnbr(int max, int info)
{
	int	i;

	i = 0;
	ft_putnbr(info);
	while ((nblen(info) + i) < max)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putchar(' ');
}

void	sub_print_dev(ll_list *current, t_static2 *opt, max_len *len)
{
	if (opt->s)
		ft_putdevnbr(len->bsize_len, current->bsize);
	ft_putstr(current->perm);
	ft_putstr(" ");
	ft_putdevnbr(len->link_len, current->link);
	if (!opt->g)
		(!opt->n) ? ft_putdevstr(len->uid_len, current->uid) :
					ft_putdevnbr(len->uid_nb_len, current->uid_nb);
}

void	print_maj_min(ll_list *current)
{
	int	maj_len;
	int	min_len;
	int i;
	
	i = 0;
	maj_len = nblen(current->major);
	min_len = nblen(current->minor);
	while (maj_len + i++ < 3)
		ft_putchar(' ');
	i = 0;
	ft_putnbr(current->major);
	ft_putstr(", ");
	while (min_len + i++ < 3)
		ft_putchar(' ');
	ft_putnbr(current->minor);
	ft_putchar(' ');
}

void		print_dev(ll_list *current, t_static2 *opt)
{
	max_len *len;

	len = get_len(current, opt);
	print_total(current, opt);
	while (current)
	{
		if (current->filename[0] != '.' || opt->a)
		{
			sub_print_dev(current, opt, len);
			if (!opt->G)
				(!opt->n) ? ft_putdevstr(len->gid_len, current->gid) :
							ft_putdevnbr(len->gid_nb_len, current->gid_nb);
			print_maj_min(current);
			ft_print_time(current->time);
			(!current->isdir) ? ft_putstr(current->filename) :
								ft_putstr_b(current->filename);
			if (current->islink)
			{
				ft_putstr(" -> ");
				ft_putstr(current->link_path);
			}
			ft_putchar('\n');
		}
		current = current->next;
	}
	free(len);
}

//http://man7.org/tlpi/code/online/diff/files/t_stat.c.html
