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

int		options_l(void)
{
	printf("placeholder options de l\n");
	return (1);
}

void	print_l(ll_list *current, t_static2 *opt)
{
	max_len *len;

	len = NULL;
	if (opt->a)
		printf("plop");
	get_len(len, current);
	//temp = current;
	ft_putchar(*current->perm);
	ft_putchar(' ');
	//ft_nblen();
	//ft_putchar
}

void	get_len(max_len *len, ll_list *current)
{
	int		i;

	i = 0;	
	while(current->next != NULL)
	{
		i = ft_strlen(current->filename);
		if (i > len->name_len)
			len->name_len = i;
		current = current->next;
	}
	printf("taille : %d\n", len->name_len);
}
