/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 14:28:41 by jwalle            #+#    #+#             */
/*   Updated: 2014/11/13 20:09:28 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		j;
	char	*str;

	if (!s || !f || *s == '\0')
		return (NULL);
	i = ft_strlen(s);
	str = ft_strnew(i);
	j = 0;
	while (i--)
	{
		str[j] = (*f)(*s);
		j++;
		s++;
	}
	str[j] = '\0';
	return (str);
}
