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

void	merge_sort(ll_list **headref, t_static2 *opt)
{
	ll_list *head;
	ll_list *a;
	ll_list *b;
	
	head  = *headref;
	if (!head || !head->next)
		return;
	split(head, &a, &b);
	merge_sort(&a, opt);
	merge_sort(&b, opt);
	
	if (opt->r && opt->dft)
		*headref = merge_r(a, b);
	if (opt->S && opt->no_r)
		*headref = merge_size(a, b);
	if (opt->S && opt->r)
		*headref = merge_size_r(a, b);
	else
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

ll_list	*merge_r(ll_list *a, ll_list *b)
{
	ll_list *result;
	
	if (!a)
		return(b);
	if (!b)
		return(a);
		
	if (ft_strcmp(a->filename, b->filename) > 0)
	{
		result = a;
		result->next = merge_r(a->next, b);
	}
	else
	{
		result = b;
		result->next = merge_r(a, b->next);
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


ll_list	*merge_size(ll_list *a, ll_list *b)
{
	ll_list *result;
	
	if (!a)
		return(b);
	if (!b)
		return(a);
		
	if (a->size > b->size)
	{
		result = a;
		result->next = merge_size(a->next, b);
	}
	else
	{
		result = b;
		result->next = merge_size(a, b->next);
	}
	return (result);
}

ll_list	*merge_size_r(ll_list *a, ll_list *b)
{
	ll_list *result;
	
	if (!a)
		return(b);
	if (!b)
		return(a);
		
	if (a->size < b->size)
	{
		result = a;
		result->next = merge_size_r(a->next, b);
	}
	else
	{
		result = b;
		result->next = merge_size_r(a, b->next);
	}
	return (result);
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