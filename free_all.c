/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 11:54:23 by jwalle            #+#    #+#             */
/*   Updated: 2015/03/05 11:55:25 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


void destroy_info(ll_list *cur)
{
	ft_strdel(&cur->filename);
	ft_strdel(&cur->gid);
	ft_strdel(&cur->perm);
	ft_strdel(&cur->uid);
	ft_strdel(&cur->perm);
	ft_strdel(&cur->uid);
	ft_strdel(&cur->gid);
}


void	free_all(ll_list *lst)
{
	if (lst)
	{
		free_all(lst->next);
		destroy_info(lst);
		free(lst);
		lst = NULL;
	}
}

