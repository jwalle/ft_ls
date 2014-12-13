/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 16:23:40 by jwalle            #+#    #+#             */
/*   Updated: 2014/11/17 12:01:27 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*temp1;
	unsigned char	*temp2;

	if (!n || !s1 || !s2)
		return (0);
	temp1 = (unsigned char*)s1;
	temp2 = (unsigned char*)s2;
	while (n--)
	{
		if (*temp1 != *temp2)
			return (*temp1 - *temp2);
		if (n)
		{
			temp1++;
			temp2++;
		}
	}
	return (0);
}
