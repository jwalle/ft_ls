/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:49:36 by jwalle            #+#    #+#             */
/*   Updated: 2014/11/08 19:12:49 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*tmp;
	const char	*tmp2;

	tmp = dst;
	tmp2 = src;
	while (n--)
	{
		if (*tmp2 == c)
		{
			*tmp++ = *tmp2++;
			return (tmp);
		}
		*tmp++ = *tmp2++;
	}
	return (NULL);
}
