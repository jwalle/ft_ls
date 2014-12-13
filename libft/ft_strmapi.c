/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 18:12:07 by jwalle            #+#    #+#             */
/*   Updated: 2014/11/13 20:09:45 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		j;
	char	*str;

	if (!s || !f)
		return (NULL);
	i = ft_strlen(s);
	str = ft_strnew(i);
	j = 0;
	while (i--)
	{
		str[j] = (*f)(j, *s);
		j++;
		s++;
	}
	return (str);
}
