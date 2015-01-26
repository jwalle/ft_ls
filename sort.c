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

void	merge_sort(ll_list **headref)
{
	ll_list *head;
	ll_list *a;
	ll_list *b;
	
	head  = *headref;
	if (!head || !head->next)
		return;
	split(head, &a, &b);
	merge_sort(&a);
	merge_sort(&b);
	
	*headref = merge(a, b);
}

ll_list	*merge(ll_list *a, ll_list *b)
{
	ll_list *result;
	
	if (!a)
		return(b);
	if (!b)
		return(a);
		
	if (ft_strcmp(a->filename, b->filename) < 0)
	{
		result = a;
		result->next = merge(a->next, b);
	}
	else
	{
		result = b;
		result->next = merge(a, b->next);
	}
	return (result);
}

void	split(ll_list *source, ll_list **front, ll_list **back)
{
	ll_list	*fast;
	ll_list *slow;
	
	if (!source || !source->next)
	{
		*front = source;
		*back = NULL;
	}
	else
	{
		slow = source;
		fast = source->next;
		while (fast)
		{
			fast = fast->next;
			if (fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		*front = source;
		*back = slow->next;
		slow->next = NULL;
	}
	
}



void	sort_str(char **str, int array_size_str)
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
