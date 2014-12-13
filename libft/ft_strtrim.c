/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 19:13:27 by jwalle            #+#    #+#             */
/*   Updated: 2014/12/08 03:29:54 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char				*str;
	unsigned int		i;
	unsigned int		j;
	unsigned int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	j = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (i == len)
		return ("");
	while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
		len = len - 1;
	str = ft_strnew(len - i);
	if (!str)
		return (NULL);
	while (s[i] != '\0' && len > i)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
