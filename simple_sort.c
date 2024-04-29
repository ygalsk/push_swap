/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:33:12 by dkremer           #+#    #+#             */
/*   Updated: 2024/04/29 15:10:23 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  get_min(t_list **stack, int val)
{
    t_list *head;
    int min;

    head = *stack;
    min = head->index;
    while (head->next)
    {
        head = head->next;
        if ((head->index < min) && head->index != val)
            min = head->index;   
    }
    return (min);
}

static void sort_3(t_list **stack_a)
{
    t_list *head;
    int min;
    int next_min;
    
    head = *stack_a;
    min = get_min(stack_a, -1);
    next_min = get_min(stack_a, min);
    if (is_sorted(stack_a))
        return;
    if (head->index == min && head->next->index != next_min)
    {
        ra(stack_a);
        sa(stack_a);
        rra(stack_a);
    }
    else if (head->index == min)
    {
        if (head->next->index == min)
            sa(stack_a);
        else
            rra(stack_a);
    }
    else
    {
        if (head->next->index == min)
            ra(stack_a);
        else
        {
            sa(stack_a);
            rra(stack_a);
        }
    }
}

static void sort_4(t_list **a, t_list **b)
{
    int distance;
    
    if (is_sorted(a))
        return ;
    distance = get_distance(a, get_min(a, -1));
    if (distance == 1)
        ra(a);
    else if (distance == 2)
    {
        ra(a);
        ra(a);
    }
    else if (distance == 3)
        rra(a);
    if (is_sorted(a))
        return ;
    pb(a, b);
    sort_3(a);
    pa(a, b);
}

static void sort_5(t_list **a, t_list **b)
{
    int distance;
    
    if (is_sorted(a))
        return ;
    distance = get_distance(a, get_min(a, -1));
    if (distance == 1)
        ra(a);
    else if (distance == 2)
    {
        ra(a);
        ra(a);
    }
    else if (distance == 3)
    {
        rra(a);
        rra(a);
    }
    else if (distance == 4)
        rra(a);
    if (is_sorted(a))
        return ;
    pb(a, b);
    sort_4(a, b);
    pa(a, b);
}

void    simple_sort(t_list **a, t_list **b)
{
    int size;
    
    if (is_sorted(a) || ft_listsize(*a) == 0 ||
        ft_listsize(*a) == 1)
        return ;
    size = ft_listsize(*a);
    if (size == 2)
        sa(a);
    else if (size == 3)
        sort_3(a);
    else if (size == 4)
        sort_4(a, b);
    else if (size == 5)
        sort_5(a, b);
}