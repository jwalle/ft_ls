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
    ll_list         *new;
    ll_list         *current;
    DIR             *dir;
    struct dirent   *dp;

    head = NULL;
    new = NULL;
    current = head;
    dir = opendir(str);
    if (dir == NULL)
        fail_open_directory(str);
    while ((dp = readdir(dir)))
    {
        if (head == NULL)
        {
            new = (ll_list*)malloc(sizeof(ll_list));
            new->next = head;
            head = new;
            new->filename = dp->d_name;
            new->isdir = can_open(dp);
            current = head;
        }
        else
        {
            while (current->next != NULL)
                current = current->next;
            new = (ll_list*)malloc(sizeof(ll_list));
            current->next = new;
            new->next = NULL;
            new->filename = dp->d_name;
            new->isdir = can_open(dp);
        }
    }
    close_directory(dir);
    current = head;
    return (current);
    /*while (current != NULL)
    {
        printf("%s dir? = %d\n", current->filename, current->isdir);
        current = current->next;
    }*/
}
/*
void    ll_copy(char *str, struct dirent *dp, ll_list *new, ll_list *current, ll_list *head)
{
    if (head == NULL)
    {
        new = (ll_list*)malloc(sizeof(ll_list));
        new->next = head;
        head = new;
        new->filename = str;
        new->isdir = can_open(dp);
        current = head;
    }
    else
    {
        while (current->next != NULL)
            current = current->next;
        new = (ll_list*)malloc(sizeof(ll_list));
        current->next = new;
        new->next = NULL;
        new->filename = str;
        new->isdir = can_open(dp);
    }
}*/