/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:54:37 by dkremer           #+#    #+#             */
/*   Updated: 2024/06/02 11:41:02 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <sys/wait.h>

static void	init_stacks(t_list **a, int argc, char **argv)
{
	t_list	*new;
	char	**args;
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		args = ft_split(argv[i], ' ');
		if (!args)
			free_and_error(args);
		j = 0;
		while (args[j])
		{
			new = ft_lstnew(ft_atol(args[j]));
			ft_lstadd_back(a, new);
			j++;
		}
		free_list(args);
		i++;
	}
}

void	sort_3(t_list **a)
{
	if (biggest(*a)->value == (*a)->value)
	{
		ra(a);
		if (smallest(*a)->value != (*a)->value)
			sa(a);
	}
	else if (smallest(*a)->value == (*a)->value)
	{
		rra(a);
		sa(a);
	}
	else if (biggest(*a)->value == ft_lstlast(*a)->value)
		sa(a);
	else
		rra(a);
}

void	handle_5(t_list **a, t_list **b)
{
	while (ft_listsize(*a) > 3)
	{
		init_index(*a);
		if (smallest(*a)->a_med)
		{
			while (smallest(*a)->index != (*a)->index)
				ra(a);
		}
		else
			while (smallest(*a)->index != (*a)->index)
				rra(a);
		pb(a, b);
	}
	if (!is_sorted(a))
		sort_3(a);
	while (*b)
		pa(a, b);
}

static void	sort(t_list **a, t_list **b)
{
	if (ft_listsize(*a) == 2)
		sa(a);
	else if (ft_listsize(*a) == 3)
		sort_3(a);
	else if (ft_listsize(*a) == 5)
		handle_5(a, b);
	else
		fast_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;

	if (argc < 2)
		return (0);
	ft_check_args(argc, argv);
	a = ft_calloc(1, sizeof(t_list));
	b = ft_calloc(1, sizeof(t_list));
	*a = NULL;
	*b = NULL;
	init_stacks(a, argc, argv);
	if (!(is_sorted(a)))
		sort(a, b);
	free_stacks(a, b);
	return (0);
}
