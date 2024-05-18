/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:51:22 by dkremer           #+#    #+#             */
/*   Updated: 2024/05/17 16:50:12 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_index(t_list *stack)
{
	int	index;
	int	median;

	index = 0;
	if (!stack)
		return ;
	median = ft_listsize(stack) / 2;
	while (stack)
	{
		stack->index = index;
		if (index <= median)
			stack->a_med = true;
		else
			stack->a_med = false;
		stack = stack->next;
		index++;
	}
}
