/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_l.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 17:54:27 by jwalle            #+#    #+#             */
/*   Updated: 2015/01/28 14:32:24 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_l(ll_list *current, t_static2 *opt)
{
	max_len *len;
	
	len = get_len(current, opt);
	print_total(current, opt);
	while (current)
	{
		if (current->filename[0] != '.' || opt->a)
		{
			if (opt->s)
			ft_putnnbr(len->bsize_len, current->bsize);
			ft_putstr(current->perm);
			ft_putstr(" ");
			ft_putnnbr(len->link_len, current->link);
			if (!opt->g)
				(!opt->n) ? ft_putnstr(len->uid_len, current->uid) : ft_putnnbr(len->uid_nb_len, current->uid_nb);
			if (!opt->G)
				(!opt->n) ? ft_putnstr(len->gid_len, current->gid) : ft_putnnbr(len->gid_nb_len, current->gid_nb);	
			ft_putnnbr(len->size_len, current->size);
			ft_print_time(current->time);
			(!current->isdir) ? ft_putstr(current->filename) 
								: ft_putstr_b(current->filename);
			ft_putchar('\n');
		}
	current = current->next;
	}
	free(len);
}

void	print_total(ll_list *current, t_static2 *opt)
{
	int total;
	
	total = 0;
	while (current)
	{
		if (current->filename[0] != '.' || opt->a)
		{
			total = total + current->bsize;
		}
	current = current->next;
	}
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putchar('\n');
}

max_len		*get_len(ll_list *current, t_static2 *opt)
{
	int		i;
	max_len *size;

	i = 0;
	size = malloc(sizeof(max_len));
	size->size_len = 0;
	size->link_len = 0;
	size->uid_len = 0;
	size->gid_len = 0;
	size->name_len = 0;
	size->day_len = 0;
	size->bsize_len = 0;
	size->uid_nb_len = 0;
	size->gid_nb_len = 0;

	while(current)
	{
		if (current->filename[0] != '.' || opt->a)
		{
			i = nblen(current->link);
			if(i > size->link_len)
				size->link_len = i;
			i = ft_strlen(current->gid);
			if(i > size->gid_len)
				size->gid_len = i;
			i = ft_strlen(current->uid);
			if(i > size->uid_len)
				size->uid_len = i;
			i = nblen(current->size);
			if(i > size->size_len)
				size->size_len = i;
			i = ft_strlen(current->filename);
			if (i > size->name_len)
				size->name_len = i;
			i = nblen(current->bsize);
			if (i > size->bsize_len)
				size->bsize_len = i;
			i = nblen(current->uid_nb);
			if (i > size->uid_nb_len)
				size->uid_nb_len = i;
			i = nblen(current->gid_nb);
			if (i > size->gid_nb_len)
				size->gid_nb_len = i;
		}
		current = current->next;
	}
	return(size);
}

void	ft_print_time(time_t timefile)
{
	char	*str;
	int		i;
	time_t current;

	str = ctime(&timefile);
	current = time(NULL);
	if (current - timefile < 0 || current - timefile >= 15552000)
	{
		i = ft_strlen(str) - 1;
		str[i] = 0;
		while(str[i] != ' ')
			--i;
		write(1, str + 4, 7);
		ft_putstr(str + i);
	}
	else
		write(1, str + 4, ft_strlen(str) - 13);
	ft_putchar(' ');
}
