/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_l.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 17:54:27 by jwalle            #+#    #+#             */
/*   Updated: 2015/01/26 17:39:34 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_l(ll_list *current, t_static2 *opt)
{
	max_len *len;
	
	printf("max_len = %d", (int)sizeof(len));
	if (opt->a)
		printf("plop");
	len = get_len(current);
	while (current)
	{
		ft_putstr(current->perm);
		ft_putchar(' ');
		ft_putnnbr(len->link_len, current->link);
		ft_putchar(' ');
		ft_putnstr(len->uid_len, current->uid);
		ft_putchar(' ');
		ft_putnstr(len->gid_len, current->gid);	
		ft_putchar(' ');
		ft_putnnbr(len->size_len, current->size);
		ft_putchar(' ');
		//ft_putnstr(len->name_len, current->filename);
		ft_putstr(current->filename);
		ft_putchar('\n');

	//ft_nblen(len);
	//ft_putchar
	current = current->next;
	}
}

max_len		*get_len(ll_list *current)
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
	while(current)
	{
	//printf("link = %d, size = %d, name = %s\n", current->link, size->size_len, current->filename);
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
		current = current->next;
	}

	//printf("link,gid,uid,size,filename : %d, %d, %d, %d, %d\n", size->link_len, size->gid_len, size->uid_len, size->size_len, size->name_len);
	return(size);
}

int		nblen(int len)
{
	int		i;
	
	i = (len <= 0 ? 1 : 0);
	while (len)
	{
		len = len/10;
		++i;
	}
	//printf("i get len = %d\n", i);
	return(i);
}

void	ft_putnstr(int max, char *str)
{
	int i;
	
	i = 0;
	while ((int)(ft_strlen(str) + i) < max)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putstr(str);
}

void	ft_putnnbr(int max, int info)
{
	int	i;
	
	i = 0;
	while ((nblen(info) + i) < max)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putnbr(info);	
}