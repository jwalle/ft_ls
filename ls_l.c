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
	
	len = get_len(current);
	while (current)
	{
		if (current->filename[0] != '.' || opt->a)
		{
		//printf("date2 : %s\n", current->date);
			ft_putstr(current->perm);
			ft_putstr("  ");
			ft_putnnbr(len->link_len, current->link);
			if (!opt->g)
				ft_putnstr(len->uid_len, current->uid);
			if (!opt->G)
				ft_putnstr(len->gid_len, current->gid);	
			ft_putnnbr(len->size_len, current->size);
			ft_print_time(*(current->time), current->date); // stocker le str aussi !
			(!current->isdir) ? ft_putstr(current->filename) 
								: ft_putstr_b(current->filename);
			ft_putchar('\n');
		}
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
	size->day_len = 0;
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
		i = ft_strlen(current->date);
		if (i > size->day_len)
			size->day_len = i;

		current = current->next;
	}

	//printf("link,gid,uid,size,filename : %d, %d, %d, %d, %d\n", size->link_len, size->gid_len, size->uid_len, size->size_len, size->name_len);
	return(size);
}

void	ft_print_time(const time_t timefile, char *str)
{
	char	*str2;
	//int		i;
	//time_t current;

	str2 = ctime(&timefile);
	//current = time(0);
	write(1, &str2, 0);
	/*if (current - timefile < 0 || current - timefile >= 15552000)
	{
		i = ft_strlen(str) - 1;
		str[i] = 0;
		while(str[i] != ' ')
			--i;
		write(1, str + 4, 7);
		ft_putstr(str + i);
	}
	else*/
		write(1, str + 4, ft_strlen(str) - 13);
	ft_putchar(' ');

}
