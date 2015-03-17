/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_l.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 17:54:27 by jwalle            #+#    #+#             */
/*   Updated: 2015/03/17 17:14:47 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sub_print_l(ll_list *current, t_static2 *opt, max_len *len)
{
	if (opt->s)
		ft_putnnbr(len->bsize_len, current->bsize);
	ft_putstr(current->perm);
	ft_putstr(" ");
	ft_putnnbr(len->link_len, current->link);
	if (!opt->g)
		(!opt->n) ? ft_putnstr(len->uid_len, current->uid) :
					ft_putnnbr(len->uid_nb_len, current->uid_nb);
}

static void	print_maj_min(ll_list *current, max_len *len)
{
	ft_putnnbr(len->maj_len, current->major);
	ft_putstr(",");
	ft_putnnbr(len->min_len, current->minor);
}

void		print_l(ll_list *current, t_static2 *opt)
{
	max_len *len;

	len = get_len(current, opt);
	print_total(current, opt);
	while (current)
	{
		if (current->filename[0] != '.' || opt->a)
		{
			sub_print_l(current, opt, len);
			if (!opt->G)
				(!opt->n) ? ft_putnstr(len->gid_len, current->gid) :
							ft_putnnbr(len->gid_nb_len, current->gid_nb);
			if(!current->major)
				ft_putnnbr(len->size_len, current->size);
			else
				print_maj_min(current, len);
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

max_len		*get_len(ll_list *current, t_static2 *opt)
{
	max_len *size;

	size = malloc(sizeof(max_len));
	size = set_size_zero(size);
	while (current)
	{
		if (current->filename[0] != '.' || opt->a)
		{
			size->link_len = check_len_nb(current->link, size->link_len);
			size->gid_len = check_len_str(current->gid, size->gid_len);
			size->uid_len = check_len_str(current->uid, size->uid_len);
			size->size_len = check_len_nb(current->size, size->size_len);
			size->name_len = check_len_str(current->filename, size->name_len);
			size->bsize_len = check_len_nb(current->bsize, size->bsize_len);
			size->uid_nb_len = check_len_nb(current->uid_nb, size->uid_nb_len);
			size->gid_nb_len = check_len_nb(current->gid_nb, size->gid_nb_len);
			size->min_len = check_len_nb(current->minor, size->min_len);
			size->maj_len = check_len_nb(current->major, size->maj_len);
		}
		current = current->next;
	}
	return (size);
}

int			check_len_nb(int n, int max)
{
	int	i;

	i = nblen(n);
	if (i > max)
		return (i);
	return (max);
}

int			check_len_str(char *str, int max)
{
	int i;

	i = ft_strlen(str);
	if (i > max)
		return (i);
	return (max);
}

//http://man7.org/tlpi/code/online/diff/files/t_stat.c.html
