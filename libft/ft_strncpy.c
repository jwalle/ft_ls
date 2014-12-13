/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:21:24 by jwalle            #+#    #+#             */
/*   Updated: 2014/11/09 10:52:09 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*ctr;

	ctr = dest;
	while (n > 0 && *src != '\0')
	{
		*ctr++ = *src++;
		--n;
	}
	while (n > 0)
	{
		*ctr++ = '\0';
		--n;
	}
	return (dest);
}
