/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 10:53:21 by jwalle            #+#    #+#             */
/*   Updated: 2014/11/26 16:42:04 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dest;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	if (!s1)
		return (NULL);
	dest = (char *)malloc(sizeof(char *) * len);
	if (dest == NULL)
		return (dest);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
