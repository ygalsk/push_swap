/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:53:16 by dkremer           #+#    #+#             */
/*   Updated: 2024/05/30 15:53:54 by dkremer          ###   ########.fr       */
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

	cheap = cheapest(*a);
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
