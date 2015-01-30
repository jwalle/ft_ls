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

void	merge_sort(ll_list **ref, t_static2 *opt)
{
	ll_list *head;
	ll_list *a;
	ll_list *b;
	
	head  = *ref;
	if (!head || !head->next)
		return;
	split(head, &a, &b);
	merge_sort(&a, opt);
	merge_sort(&b, opt);
	
	if (opt->S)
		(opt->r) ? (*ref = merge_size_r(a, b)) : (*ref = merge_size(a, b));
	if (opt->t)
		(opt->r) ? (*ref = merge_time_r(a, b)) : (*ref = merge_time(a, b));
	if (opt->dft)
		(opt->r) ? (*ref = merge_r(a, b)) : (*ref = merge(a, b));
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