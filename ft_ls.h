/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 17:36:17 by jwalle            #+#    #+#             */
/*   Updated: 2015/03/09 13:18:54 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <dirent.h>
# include <stdlib.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <stdio.h>		//PRINTF A RETIRER
# include "libft.h"

# define RESET "\033[0m"
# define BOLD "\033[1m"

typedef	struct		s_static
{
	int				name_len;
	int				link_len;
	int				uid_len;
	int				uid_nb_len;
	int				gid_len;
	int				gid_nb_len;
	int				size_len;
	int				bsize_len;
	int				maj_len;
	int				min_len;
}					max_len;

typedef struct		element
{
	char			*filename;
	dev_t			device;
	int				isdir;
	int				islink;
	char			*perm;
	int				link;
	char			*link_path;
	char			*uid;
	int				uid_nb;
	char			*gid;
	int				gid_nb;
	int				size;
	int				bsize;
	time_t			time;
	long			major;
	long			minor;
	struct element	*next;
}					ll_list;

typedef struct		s_static2
{
	char			sort;
	int				l;
	int				R;
	int				a;
	int				r;
	int				no_r;
	int				A;
	int				d;
	int				g;
	int				G;
	int				i;
	int				n;
	int				s;
	int				v;
	int				dft;
}					t_static2;

typedef	struct		directory	
{
	char			*str;
	struct element2 *next;
}					d_list;

int					main(int ac, char **av);
ll_list				*fail_open_directory(char *str);
struct dirent		*get_content(DIR *dir);
void				close_directory(DIR *dir);
int					can_open(struct dirent *dp, char *str);
char				*correct_path(char *s1, char *s2);
int					error(char c);
ll_list				*ll_stock(char *str);
ll_list				*ll_copy_new(char *str, struct dirent *dp,
											ll_list *head, char *str2);
ll_list				*ll_copy_cur(char *str, struct dirent *dp,
											ll_list *cur, char *str2);
void				ft_putstr_b(char *str);
void				ft_ls(t_static2 *opt, ll_list *cur);
int					options(char *av, t_static2 *opt);
int					options2(char *av, t_static2 *opt);
int					options3(char *av, t_static2 *opt);
int					choose_prog(t_static2 *opt, char *av);
int					options_l(void);
int					get_info_l(void);
int					align_info(void);
void				sort_num(int a[], int array_size, int rev);
void				sort_str(char **str, int array_size_str);
void				merge_sort(ll_list **ref, t_static2 *opt);
ll_list				*merge(ll_list *a, ll_list *b);
ll_list				*merge_r(ll_list *a, ll_list *b);
ll_list				*merge_size(ll_list *a, ll_list *b);
ll_list				*merge_size_r(ll_list *a, ll_list *b);
ll_list				*merge_time(ll_list *a, ll_list *b);
ll_list				*merge_time_r(ll_list *a, ll_list *b);
void				split(ll_list *source, ll_list **front, ll_list **back);
void				get_info(struct dirent *dp, ll_list *current, char *str);
void				get_permission(struct stat filestat, ll_list *current);
void				print_l(ll_list *curent, t_static2 *opt);
max_len				*get_len(ll_list *current, t_static2 *opt);
int					nblen(int len);
void				ft_putnstr(int max, char *str);
void				ft_putnnbr(int max, int info);
void				ft_print_time(time_t timefile);
void				ft_print_r(char *av, t_static2 *opt, ll_list *cur);
void				print_total(ll_list *current, t_static2 *opt);
void				print_parsed(char *str, t_static2 *opt, int i);
void				print_folder(char *str);
void				ft_parse(char **av, t_static2 *opt);
int					is_opt(char *str);
char				file_type(struct stat filestat);
void				free_all(ll_list *cur);
int					check_len_nb(int n, int max);
int					check_len_str(char *str, int max);
max_len				*set_size_zero(max_len *size);
void				get_info_file(ll_list *current, struct stat filestat);
void				min_maj(ll_list *current);
ll_list				*ll_copy_new_file(char *str, ll_list *head,
										struct stat filestat);

#endif
