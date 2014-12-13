/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:32:34 by jwalle            #+#    #+#             */
/*   Updated: 2014/11/16 19:33:39 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned int	i;

	i = 0;
	if (!s || !n)
		return (NULL);
	str = (unsigned char*)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void*)str + i);
		i++;
	}
	return (NULL);
}
