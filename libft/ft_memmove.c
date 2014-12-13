/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 12:07:09 by jwalle            #+#    #+#             */
/*   Updated: 2014/11/21 15:47:25 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*tmp;
	const char	*tmp2;

	if (dst == NULL || src == NULL || n == 0)
		return (NULL);
	tmp = dst;
	tmp2 = src;
	if (dst <= src)
		return (ft_memcpy(dst, src, n));
	tmp += n;
	tmp2 += n;
	while (n--)
		*--tmp = *--tmp2;
	return (dst);
}
