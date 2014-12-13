/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 16:20:14 by jwalle            #+#    #+#             */
/*   Updated: 2014/12/08 03:32:21 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_fill(char *str, int len, int n, int j)
{
	while (n)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	if (j == 1)
		str[len] = '-';
	return (str);
}

static char		*ft_bignum(char *str)
{
	str = "-2147483648";
	return (str);
}

static char		*ft_iszero(char *str)
{
	str = ft_strnew(1);
	str[0] = '0';
	return (str);
}

static int		ft_lennbr(int n)
{
	int j;

	j = 0;
	while (n != 0)
	{
		n = n / 10;
		j++;
	}
	return (j);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		j;

	str = NULL;
	if (n == 0)
		return (ft_iszero(str));
	j = 0;
	len = ft_lennbr(n);
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		if (n == -2147483648)
			return (ft_bignum(str));
		n = n * -1;
		len++;
		j = 1;
	}
	len--;
	return (ft_fill(str, len, n, j));
}
