/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:42:54 by dkremer           #+#    #+#             */
/*   Updated: 2024/05/30 14:43:44 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*biggest(t_list *stack)
{
	t_list	*big;

	if (!stack)
		return (NULL);
	if (stack)
		big = stack;
	while (stack)
	{
		if (stack->value > big->value)
			big = stack;
		stack = stack->next;
	}
	return (big);
}

t_list	*smallest(t_list *stack)
{
	t_list	*small;

	if (stack)
		small = stack;
	while (stack)
	{
		if (stack->value < small->value)
			small = stack;
		stack = stack->next;
	}
	return (small);
}

t_list	*cheapest(t_list *b)
{
	t_list	*best_node;

	best_node = b;
	while (b)
	{
		if (b->price < best_node->price)
			best_node = b;
		b = b->next;
	}
	return (best_node);
}

void	init_nodes_a(t_list *a, t_list *b)
{
	init_index(a);
	init_index(b);
	set_target_a(a, b);
	get_price_b(a, b);
}

void	init_nodes_b(t_list *a, t_list *b)
{
	init_index(a);
	init_index(b);
	set_target_b(a, b);
	get_price_a(a, b);
}
