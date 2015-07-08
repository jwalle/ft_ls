/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/20 18:12:34 by jwalle            #+#    #+#             */
/*   Updated: 2015/05/20 18:23:46 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ll_copy_new(t_list *lst, t_list *head)
{
	t_list *new;

	new = (t_list*)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->next = head;
	head = new;
	new->content = ft_strdup((char*)lst->content);
	new->content_size = lst->content_size;
	return (new);
}

static t_list	*ll_copy_cur(t_list *lst, t_list *cur)
{
	t_list *new;

	new = (t_list*)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	cur->next = new;
	new->next = NULL;
	new->content = ft_strdup((char*)lst->content);
	new->content_size = lst->content_size;
	return (new);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *copy;
	t_list *head;

	head = NULL;
	copy = head;
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (head == NULL)
		{
			head = ll_copy_new(f(lst), head);
			copy = head;
		}
		else
		{
			while (copy->next != NULL)
				copy = copy->next;
			copy = ll_copy_cur(f(lst), copy);
		}
		lst = lst->next;
	}
	return (head);
}
