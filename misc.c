/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 14:48:03 by jwalle            #+#    #+#             */
/*   Updated: 2015/01/28 14:48:07 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		nblen(int len)
{
	int		i;
	
	i = (len <= 0 ? 1 : 0);
	while (len)
	{
		len = len/10;
		++i;
	}
	//printf("i get len = %d\n", i);
	return(i);
}

void	ft_putnstr(int max, char *str)
{
	int i;
	
	i = 0;
	while ((int)(ft_strlen(str) + i) < max)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putstr(str);
	ft_putstr(" ");
}

void	ft_putnnbr(int max, int info)
{
	int	i;
	
	i = 0;
	while ((nblen(info) + i) < max)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putnbr(info);
	ft_putchar(' ');
}

int	is_opt(char *str)
{
	if (str[0] == '-')
	{
		if (str[1] != '\0')
			return (1);
		else
		{
			fail_open_directory(str);
			return (-1);
		}
	}
	else
		return (0);
	return (0);
}
