/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:31:38 by dkremer           #+#    #+#             */
/*   Updated: 2024/04/28 15:31:38 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int swap(t_list **stack)
{
    t_list *head;
    t_list *next;
    int tmp_val;
    int tmp_index;

    if (ft_listsize(*stack) < 2)
        return (-1);
    head = *stack;
    next = head->next;
    if (!head && !next)
        error();
    tmp_val = head->value;
    tmp_index = head->index;
    head->value = next->value;
    head->index = next->index;
    next->value = tmp_val;
    next->index = tmp_index;
    return (0);   
}

int sa(t_list **stack_a)
{
    if (swap(stack_a) == -1)
        return (-1);
    ft_putendl_fd("sa", 1);
    return (0);
}

int sb(t_list **stack_b)
{
    if (swap(stack_b) == -1)
        return (-1);
    ft_putendl_fd("sb", 1);
    return (0);
}

int ss(t_list **stack_a, t_list **stack_b)
{
    if ((ft_listsize(*stack_a) < 2) || (ft_listsize(*stack_b) < 2))
        return (-1);
    swap(stack_a);
    swap(stack_b);
    ft_putendl_fd("ss", 1);
    return (0);
}

int rotate(t_list **stack)
{
    t_list *head;
    t_list *tail;

    if (ft_listsize(*stack) < 2)
        return (-1);
    head = *stack;
    tail = ft_lstlast(head);
    *stack = head->next;
    head->next = NULL;
    tail->next = head;
    return (0);
}

int ra(t_list **stack_a)
{
    if (rotate(stack_a) == -1)
        return (-1);
    ft_putendl_fd("ra", 1);
    return (0);
}

int rb(t_list **stack_b)
{
    if (rotate(stack_b) == -1)
        return (-1);
    ft_putendl_fd("rb", 1);
    return (0);
}

int rr(t_list **stack_a, t_list **stack_b)
{
    if ((ft_listsize(*stack_a) < 2) || (ft_listsize(*stack_b) < 2))
        return (-1);
    rotate(stack_a);
    rotate(stack_b);
    ft_putendl_fd("rr", 1);
    return (0);
}