/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:55:05 by dkremer           #+#    #+#             */
/*   Updated: 2024/05/30 14:55:03 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int value)
{
	t_list	*new;

	new = (t_list *)ft_calloc(1, sizeof(*new));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp->next)
	{
		temp = temp->next;
		if (temp->next == NULL)
			return (temp);
	}
	return (temp);
}

void	ft_lstadd_back(t_list **stack, t_list *new_node)
{
	t_list	*n;

	if (*stack)
	{
		n = ft_lstlast(*stack);
		n->next = new_node;
		new_node->next = NULL;
	}
	else
	{
		*stack = new_node;
		(*stack)->next = NULL;
	}
}

int	ft_listsize(t_list *head)
{
	size_t	i;
	t_list	*temp;

	temp = head;
	i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

bool	is_sorted(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (false);
		head = head->next;
	}
	return (true);
}
