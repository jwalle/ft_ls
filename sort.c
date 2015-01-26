/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 17:46:15 by jwalle            #+#    #+#             */
/*   Updated: 2014/12/13 19:24:13 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void swap(struct ll_list *a, ll_list *b)
{
	char *temp;
	
	temp = a->;
	a->filename
}



















void		sort_str(char **str, int array_size_str)
{
	char	i;
	int		j;
	char	*temp;

	i = 0;
	while (i < (array_size_str - 1))
	{
		j = 0;
		while (j < (array_size_str - 1 - i))
		{
			if (strcmp(str[j], str[j+1]) > 0)
			{
				temp = str[j+1];
				str[j+1] = str[j];
				str[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	sort_num(int a[], int array_size, int rev)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	while (i < (array_size - 1))
	{
		j = 0;
		while (j < (array_size - 1 - i))
		{
			if (rev == 0)
			{
				if (a[j] > a[j+1])
				{
					temp = a[j+1];
					a[j+1] = a[j];
					a[j] = temp;
				}
			}
			else
			{
				if (a[j] < a[j+1])
				{
					temp = a[j+1];
					a[j+1] = a[j];
					a[j] = temp;
				}
			}
			j++;
		}
		i++;
	}
} // trop long. faire un sort et un sort_r pour CHAQUE...?

int		sort_date(void)
{
	printf("placeholder date\n");
	return (1);
}

int		sort_size(void)
{
	printf("placeholder sort size bonus\n");
	return (1);
}

int		sort_version(void)
{
	printf("placeholder sort version bonus\n");
	return (1);
}

int		sort_reverse(void)
{
	printf("placeholder sort reverse\n");
	return (1);
}
