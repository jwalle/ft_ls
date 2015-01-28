/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_R.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 14:50:53 by jwalle            #+#    #+#             */
/*   Updated: 2015/01/28 16:26:03 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		**stock_R(char *str, t_static2 *opt)
{
/*	d_list			*head;
	d_list			*current;i*/
	DIR				*dirlist;
	struct dirent 	*dp;
	struct stat		*stat;
	char			**list;
	int				i;
	char			*d_path;

	dir = opendir(str);
	if(dir == NULL)
		fail_open_directory(str);
	d_path = correct_path(str, dp->d_name);
	stat(path, &stat);
	while (dp = readdir(dirlist))
	{
		if (S_ISDIR(stat.st_mode))
			stock_R(dp->d_name, opt);
		*list = dp->d_name;
		*list++;
	}
	return (*list);
}

str		*stock(d_list *head)
{
	while (d)
}
