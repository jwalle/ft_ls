/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 20:15:54 by jwalle            #+#    #+#             */
/*   Updated: 2014/11/20 15:42:29 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*tmp;
	char		*tmp2;

	tmp = (char*)dst;
	tmp2 = (char*)src;
	while (n--)
		*tmp++ = *tmp2++;
	return (dst);
}
