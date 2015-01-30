/*--HEADER--*/

#include "ft_ls.h"

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

ll_list	*merge_time(ll_list *a, ll_list *b)
{
	ll_list *result;
	
	if (!a)
		return(b);
	if (!b)
		return(a);
		
	if (a->time > b->time)
	{
		result = a;
		result->next = merge_time(a->next, b);
	}
	else
	{
		result = b;
		result->next = merge_time(a, b->next);
	}
	return (result);
}

ll_list	*merge_time_r(ll_list *a, ll_list *b)
{
	ll_list *result;
	
	if (!a)
		return(b);
	if (!b)
		return(a);
		
	if (a->time < b->time)
	{
		result = a;
		result->next = merge_time_r(a->next, b);
	}
	else
	{
		result = b;
		result->next = merge_time_r(a, b->next);
	}
	return (result);
}