/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:45:35 by dkremer           #+#    #+#             */
/*   Updated: 2024/04/19 15:49:50 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	free_list(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

bool	is_sorted(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (true);
		head = head->next;
	}
	return (false);
}

void	free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*temp;

	head = *stack;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	free(stack);
}

void	free_stacks(t_list **a, t_list **b)
{
	free_stack(a);
	free_stack(b);
}

int	get_distance(t_list **stack, int index)
{
	t_list *head;
	int	dist;

	dist = 0;
	head = *stack;
	while (head)
	{
		if (head->index == index)
			break;
		dist++;
		head = head->next;
	}
	return (dist);
}

static void	*next_min(t_list **stack)
{
	t_list *head;
	t_list *min;
	int	checker;

	min = NULL;
	checker = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!checker || head->value < min->value))
			{
				min = head;
				checker = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	stack_index(t_list **stack)
{
	t_list *head;
	int	index;

	index = 0;
	head = next_min(stack);
	while (head)
	{
		head->index = index ++;
		head = next_min(stack);
	}
	
}