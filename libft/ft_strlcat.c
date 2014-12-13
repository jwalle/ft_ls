/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:54:56 by jwalle            #+#    #+#             */
/*   Updated: 2014/11/11 14:19:21 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	int				i;
	unsigned int	lensrc;
	unsigned int	lendest;

	i = 0;
	lendest = ft_strlen(dest);
	lensrc = ft_strlen(src);
	if (size <= lendest)
		return (lensrc + size);
	while (lendest + i < size - 1)
	{
		dest[lendest + i] = src[i];
		i++;
	}
	dest[lendest + i] = '\0';
	return (lendest + lensrc);
}
