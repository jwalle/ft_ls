/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 18:02:22 by jwalle            #+#    #+#             */
/*   Updated: 2014/12/13 18:28:26 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_putstr_b(char *str)
{
	ft_putstr(ANSI_COLOR_RED);
	ft_putstr(str);
	ft_putstr(RESET);
}

int		output(void)
{
	printf("placeholder output\n");
	return (1);
}

int		clean(void)
{
	printf("placeholder clean\n");
	return (1);
}
