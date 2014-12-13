/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 17:36:17 by jwalle            #+#    #+#             */
/*   Updated: 2014/12/13 19:23:53 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FT_LS_H
#define		FT_LS_H
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>		//PRINTF A RETIRER
#include "libft.h"

/*typedef struct		s_static
{
	char	*buf;
	int		i;
}					t_static;*/


int		open_directory(void);
int		get_content(void);
int		close_directory(void);
int		check(void);
int		options(void);
int		choose_prog(void);
int		options_l(void);
int		get_info_l(void);
int		align_info(void);
void	sort_num(int a[], int array_size, int rev);
void	sort_str(char **str, int array_size_str);
int		sort_date(void);
int		sort_size(void);
int		sort_version(void);
int		sort_reverse(void);
int		output(void);
int		clean(void);

#endif
