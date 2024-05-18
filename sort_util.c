/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:06:26 by dkremer           #+#    #+#             */
/*   Updated: 2024/05/18 17:14:45 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_b(t_list *a, t_list *b)
{
	t_list	*curr_a;
	t_list	*target;
	long	best_match;

	if (!b)
		return ;
	while (b)
	{
		best_match = INT_MAX;
		curr_a = a;
		while (curr_a)
		{
			if (curr_a->value > b->value && curr_a->value < best_match)
			{
				best_match = curr_a->value;
				target = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (best_match == INT_MAX)
			b->target = smallest(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	set_target_a(t_list *a, t_list *b)
{
	t_list	*curr_b;
	t_list	*target;
	long	best_match;

	if (!a)
		return ;
	while (a)
	{
		best_match = INT_MIN;
		curr_b = b;
		while (curr_b)
		{
			if (curr_b->value < a->value && curr_b->value > best_match)
			{
				best_match = curr_b->value;
				target = curr_b;
			}
			curr_b = curr_b->next;
		}
		if (best_match == INT_MIN)
			a->target = biggest(b);
		else
			a->target = target;
		a = a->next;
	}
}

void	get_price_a(t_list *a, t_list *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_listsize(a);
	len_b = ft_listsize(b);
	while (b)
	{
		b->price = b->index;
		if (!(b->a_med))
			b->price = len_b - (b->index);
		if (b->target->a_med)
			b->price += b->target->index;
		else
			b->price += len_a - (b->target->index);
		b = b->next;
	}
}

void	get_price_b(t_list *a, t_list *b)
{
	int	len_a;
	int	len_b;

	len_b = ft_listsize(a);
	len_a = ft_listsize(b);
	while (a)
	{
		a->price = a->index;
		if (!(a->a_med))
			a->price = len_b - (a->index);
		if (a->target->a_med)
			a->price += a->target->index;
		else
			a->price += len_a - (a->target->index);
		a = a->next;
	}
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
