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

void	free_all(ll_list *cur)
{
	while (cur)
	{
		free(cur->filename);
		free(cur->gid);
		free(cur->perm);
		//free(cur->uid);
		//if (cur->link_path)
		//	free(cur->link_path);

		cur = cur->next;
	}
		free(cur);	
}
