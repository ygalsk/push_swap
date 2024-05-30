/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:36:02 by dkremer           #+#    #+#             */
/*   Updated: 2024/05/30 15:54:22 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finish_rotation_a(t_list **a, t_list **b, t_list *cheap)
{
	while (cheap->target != *a)
	{
		if (cheap->target->a_med)
			ra(a);
		else
			rra(a);
	}
	while (cheap != *b)
	{
		if (cheap->a_med)
			rb(b);
		else
			rrb(b);
	}
}

void	finish_rotation_b(t_list **a, t_list **b, t_list *cheap)
{
	while (cheap->target != *b)
	{
		if (cheap->target->a_med)
			rb(b);
		else
			rrb(b);
	}
	while (cheap != *a)
	{
		if (cheap->a_med)
			ra(a);
		else
			rra(a);
	}
}

void	fast_sort(t_list **a, t_list **b)
{
	t_list	*smallest_node;

	pb(a, b);
	while (ft_listsize(*a) > 3)
	{
		init_nodes_a(*a, *b);
		move_b(a, b);
	}
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_a(a, b);
	}
	init_index(*a);
	smallest_node = smallest(*a);
	if (smallest_node->a_med)
		while (*a != smallest_node)
			ra(a);
	else
		while (*a != smallest_node)
			rra(a);
}
