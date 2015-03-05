/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 14:50:53 by jwalle            #+#    #+#             */
/*   Updated: 2015/03/05 12:48:15 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_r(char *av, t_static2 *opt, ll_list *cur)
{
	char	*path;

	while (cur)
	{
		if (cur->filename[0] != '.' || opt->a)
		{
			if (cur->isdir && ft_strcmp(cur->filename, ".")
							&& ft_strcmp(cur->filename, ".."))
			{
				path = correct_path(av, cur->filename);
				cur = cur->next;
				choose_prog(opt, path);
			}
			else
				cur = cur->next;
		}
		else
			cur = cur->next;
	}
}
