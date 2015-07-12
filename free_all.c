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
	if (&cur->filename)
		ft_strdel(&cur->filename);
	if (&cur->gid)
		ft_strdel(&cur->gid);
	if (&cur->perm)
		ft_strdel(&cur->perm);
	if (&cur->uid)
		ft_strdel(&cur->uid);
	//if (cur->islink)
	//	ft_strdel(&cur->link_path);
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
