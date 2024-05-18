/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:55:05 by dkremer           #+#    #+#             */
/*   Updated: 2024/05/17 16:45:42 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <sys/wait.h>

t_list	*ft_lstnew(int value)
{
	t_list	*new;

	new = (t_list *)calloc(1, sizeof(*new));
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

void	print_list(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp)
	{
		ft_putnbr_fd(temp->value, 1);
		ft_putendl_fd("", 1);
		temp = temp->next;
	}
}

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
