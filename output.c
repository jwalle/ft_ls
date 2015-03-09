/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 18:02:22 by jwalle            #+#    #+#             */
/*   Updated: 2015/03/09 13:22:22 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_putstr_b(char *str)
{
	//ft_putstr(BOLD);
	ft_putstr(str);
	//ft_putstr(RESET);
}

void	print_parsed(char *str, t_static2 *opt, int i)
{
	struct stat	filestat;

	if (!stat(str, &filestat) && (opendir(str)))
	{
		ft_putstr(str);
		ft_putstr(":\n");
	}
	choose_prog(opt, str);
	if (/*!stat(str, &filestat)*/i > 0)
		ft_putchar('\n');
}

void	print_folder(char *str)
{
	ft_putstr(str);
	ft_putstr(":\n");
}

void	print_total(ll_list *current, t_static2 *opt)
{
	int total;

	total = 0;
	while (current)
	{
		if (current->filename[0] != '.' || opt->a)
		{
			total = total + current->bsize;
		}
		current = current->next;
	}
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putchar('\n');
}

void	ft_print_time(time_t timefile)
{
	char	*str;
	int		i;
	time_t	current;

	str = ctime(&timefile);
	current = time(NULL);
	if (current - timefile < 0 || current - timefile >= 15552000)
	{
		i = ft_strlen(str) - 1;
		str[i] = 0;
		while (str[i] != ' ')
			--i;
		write(1, str + 4, 7);
		ft_putstr(str + i);
	}
	else
		write(1, str + 4, ft_strlen(str) - 13);
	ft_putchar(' ');
}
