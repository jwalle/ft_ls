/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:21:06 by jwalle            #+#    #+#             */
/*   Updated: 2014/11/13 19:24:21 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*str;
	char	d;

	d = c;
	i = 0;
	str = (char*)s;
	if (s)
	{
		while (s[i] != '\0')
		{
			if (s[i] == d)
				return (str + i);
			i++;
		}
		if (d == 0)
			return (str + i);
	}
	return (NULL);
}
