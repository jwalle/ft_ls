/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 20:29:51 by jwalle            #+#    #+#             */
/*   Updated: 2014/11/08 19:30:40 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, int n)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	if (n < 0)
	{
		while (src[j] != '\0')
			dest[i++] = src[j++];
		dest[i] = '\0';
		return (dest);
	}
	else
	{
		while (src[j] != '\0' && n-- > 0)
			dest[i++] = src[j++];
	}
	dest[i] = '\0';
	return (dest);
}
