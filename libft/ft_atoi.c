/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 10:25:27 by jwalle            #+#    #+#             */
/*   Updated: 2014/12/08 03:33:00 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int r;
	int np;

	np = 1;
	r = 0;
	if (!(*str))
		return (0);
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\r' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
	{
		np = (*str == '-' ? -1 : 1);
		str++;
	}
	while (*str == '0')
		str++;
	while (ft_isdigit(*str))
	{
		r = r * 10 + (*str - 48);
		str++;
	}
	return (r * np);
}
