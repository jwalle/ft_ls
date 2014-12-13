/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 14:26:41 by jwalle            #+#    #+#             */
/*   Updated: 2014/11/13 20:08:38 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;
	int	j;

	if (s != NULL && f != NULL)
	{
		i = ft_strlen(s);
		j = 0;
		while (i--)
		{
			(*f)(j, s);
			s++;
			j++;
		}
	}
}
