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

ll_list     *ll_stock(char *str)
{
    ll_list         *head;
    ll_list         *current;
    DIR             *dir;
    struct dirent   *dp;

    head = NULL;
    current = head;
    dir = opendir(str);
    if (dir == NULL)
        fail_open_directory(str);
    while ((dp = readdir(dir)))
    {
        if (head == NULL)
        {
            head = ll_copy_new(dp->d_name, dp, head, str);
            current = head;
        }
        else
        {
            while (current->next != NULL)
                current = current->next;
            current = ll_copy_current(dp->d_name, dp, current, str);
        }
    }
    close_directory(dir);
    return (head);
}

ll_list    *ll_copy_new(char *str, struct dirent *dp, ll_list *head, char *str2)
{
    ll_list *new;

    new = (ll_list*)malloc(sizeof(ll_list));
    new->next = head;
    head = new;
    new->filename = str;
    new->isdir = can_open(dp, str2);
    return (new);
}

ll_list    *ll_copy_current(char *str, struct dirent *dp, ll_list *current, char *str2)
{
    ll_list *new;

    new = (ll_list*)malloc(sizeof(ll_list));
    current->next = new;
    new->next = NULL;
    new->filename = str;
    new->isdir = can_open(dp, str2);
    return (new);
}