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

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define ANSI_COLOR_RED     "\x1b[31m"

typedef struct		element
{
	char			*filename;
	int				isdir;
	struct element	*next;
	
}					ll_list;

typedef struct		s_static2
{
	int				l;
	int				R;
	int				a;
	int				r;
	int				t;
	int				A;
	int				d;
	int				g;
	int				G;
	int				i;
	int				n;
	int				S;
	int				v;
}					t_static2;

int					main(int ac, char **av);
void				fail_open_directory(char *str);
struct dirent 		*get_content(DIR *dir);
void				close_directory(DIR *dir);
int					can_open(struct dirent *dp, char *str);
char				*correct_path(char *s1, char *s2);
int					error(char c);
ll_list				*ll_stock(char *str);
ll_list    			*ll_copy_new(char *str, struct dirent *dp, ll_list *head, char *str2);
ll_list				*ll_copy_current(char *str, struct dirent *dp, ll_list *current, char *str2);
void				ft_putstr_bold(char *str);
void				ft_ls(char *str, t_static2 *opt);
void				options(char *av, t_static2 *opt);
void				options2(char *av, t_static2 *opt);
int					choose_prog(t_static2 *opt);
int					options_l(void);
int					get_info_l(void);
int					align_info(void);
void				sort_num(int a[], int array_size, int rev);
void				sort_str(char **str, int array_size_str);
int					sort_date(void);
int					sort_size(void);
int					sort_version(void);
int					sort_reverse(void);
int					output(void);
int					clean(void);

#endif
