/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:07:38 by dkremer           #+#    #+#             */
/*   Updated: 2024/04/28 15:07:38 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void lst_addfront(t_list **root, int value)
{
    t_list *new;
    new = (t_list *)ft_calloc(1, sizeof(t_list));
    if (!new)
        error();
    new->value = value;
    new->next = *root;
    *root = new;
}

void    lst_addback(t_list **root, int value)
{
    t_list  *new;
    t_list  *curr;

    new = (t_list *)ft_calloc(1, sizeof(t_list));
    if (!new)
        error();
    new->next = NULL;
    new->value = value;
    curr = *root;
    while (curr->next)
        curr = curr->next;
    curr->next = new;
}