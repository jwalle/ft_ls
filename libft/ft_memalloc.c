/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 11:48:36 by jwalle            #+#    #+#             */
/*   Updated: 2014/11/21 16:16:52 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char			*mem;

	if (!(mem = (char *)malloc(size)))
		return (NULL);
	ft_memset(mem, 0, size);
	return ((void *)mem);
}
