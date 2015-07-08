/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 15:13:03 by jwalle            #+#    #+#             */
/*   Updated: 2015/05/12 15:45:34 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		letters(char const *s, char c)
{
	int l;

	l = 0;
	while (s[l] && s[l] != c)
		l++;
	return (l);
}

static int		words(char const *s, char c)
{
	unsigned int		words;
	unsigned int		i;
	unsigned int		j;

	words = 0;
	i = 0;
	j = 0;
	if (s == 0)
		return (0);
	while (s[i])
	{
		j = letters(s + i, c);
		if (j)
		{
			words++;
			i += j;
		}
		else
			i++;
	}
	return (words);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		nbw;
	int		nbl;

	i = 0;
	nbw = 0;
	if (s == 0)
		return (0);
	if ((tab = (char**)malloc(sizeof(char*) * (words(s, c) + 1))) == NULL)
		return (NULL);
	while (s[i])
	{
		nbl = letters((char*)s + i, c);
		if (nbl)
		{
			tab[nbw] = ft_strsub(s, i, nbl);
			nbw++;
			i += nbl;
		}
		else
			i++;
	}
	tab[nbw] = 0;
	return (tab);
}
