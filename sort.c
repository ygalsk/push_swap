/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:36:02 by dkremer           #+#    #+#             */
/*   Updated: 2024/05/18 17:12:48 by dkremer          ###   ########.fr       */
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
