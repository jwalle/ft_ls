/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 11:42:33 by jwalle            #+#    #+#             */
/*   Updated: 2014/11/20 15:21:43 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*new;

	i = -1;
	new = (char*)malloc(size + 1);
	if (!new)
		return (NULL);
	while (++i < size + 1)
		new[i] = '\0';
	return (new);
}
