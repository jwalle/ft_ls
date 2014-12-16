/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 17:46:15 by jwalle            #+#    #+#             */
/*   Updated: 2014/12/13 19:24:13 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ll_stock(char *str)
{
    ll_list         *ll;
    ll_list         *ptr;
    DIR             *dir;
    struct dirent   *dp;
    
    dir = opendir(str);
    if (dir == NULL)
        fail_open_directory(str);
    ll = NULL;
    while ((dp = readdir(dir)))
    {
        //printf("plop %s\n", dp->d_name);
        if (ll == NULL)
        {
            ll = malloc(sizeof(ll_list));
            ll->filename = dp->d_name;
            ll->next = NULL;
            ptr = ll;
            //printf("plop%s\n", ll->filename);
        }
        else
        {
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = malloc(sizeof(ll_list));
            ptr->next->filename = dp->d_name;
            ptr->next->next = NULL;
            //printf("moi : %s; le readdir : %s\n", ptr->filename, dp->d_name);
        }
    }
    close_directory(dir);
    //ll_list *ptr2;
    //ptr2 = ll;
    while (ll->next != NULL)
    {
        printf("%s\n", ll->next->filename);
        ll = ll->next;
    }
}

/*
ll_list	*newnode(char *content, size_t content_size)
{
	ll_list	*new;

	if ((new = (ll_list*)malloc(sizeof(*new))) == NULL)
		return (NULL);
	if (content == NULL)
		new->filename = NULL;
	else
	{
		if ((new->filename = malloc(content_size)) == 0)
			return (NULL);
		new->filename = ft_memcpy(new->filename, content, content_size);
	}
	new->next = NULL;
	return (new);
}*/