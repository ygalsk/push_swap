/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:36:02 by dkremer           #+#    #+#             */
/*   Updated: 2024/05/18 17:17:36 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_list **a, t_list **b, t_list *cheap)
{
	while (*a != cheap->target && *b != cheap->target)
		rr(a, b);
	init_index(*a);
	init_index(*b);
}

static void	rr_both(t_list **a, t_list **b, t_list *cheap)
{
	while (*a != cheap->target && *b != cheap->target)
		rrr(a, b);
	init_index(*a);
	init_index(*b);
}

void	move_a(t_list **a, t_list **b)
{
	t_list	*cheap;

	cheap = cheapest(*b);
	if (cheap->a_med && cheap->target->a_med)
	{
		while (cheap != *b && cheap->target != *a)
			rotate_both(a, b, cheap);
		init_index(*a);
		init_index(*b);
	}
	else if (!(cheap->a_med) && !(cheap->target->a_med))
	{
		while (cheap != *b && cheap->target != *a)
			rr_both(a, b, cheap);
		init_index(*a);
		init_index(*b);
	}
	finish_rotation_a(a, b, cheap);
	pa(a, b);
}

void	move_b(t_list **a, t_list **b)
{
	t_list	*cheap;

	cheap = cheapest(*b);
	if (cheap->a_med && cheap->target->a_med)
	{
		while (cheap != *a && cheap->target != *b)
			rotate_both(a, b, cheap);
		init_index(*a);
		init_index(*b);
	}
	else if (!(cheap->a_med) && !(cheap->target->a_med))
	{
		while (cheap != *a && cheap->target != *b)
			rr_both(a, b, cheap);
		init_index(*a);
		init_index(*b);
	}
	finish_rotation_b(a, b, cheap);
	pb(a, b);
}

void	fast_sort(t_list **a, t_list **b)
{
	t_list	*smallest_node;
	int		len_a;

	len_a = ft_listsize(*a);
	if (len_a == 5)
		handle_5(a, b);
	else
	{
		while (len_a-- > 3)
			pb(a, b);
	}
	if (!is_sorted(a))
		sort_3(a);
	while (ft_listsize(*a) > 1)
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
