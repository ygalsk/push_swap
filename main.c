/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:54:37 by dkremer           #+#    #+#             */
/*   Updated: 2024/04/21 15:40:42 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/include/libft.h"
#include "push_swap.h"

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
		{
			free_list(args);
			error();
		}
		j = 0;
		while (args[j])
		{
			new = ft_lstnew(ft_atoi(args[j]));
			ft_lstadd_back(a, new);
			j++;
		}
		free_list(args);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;

	(void)argv;
	if (argc <= 2)
		return (0);
	ft_check_args(argc, argv);
	a = ft_calloc(1, sizeof(t_list));
	b = ft_calloc(1, sizeof(t_list));
	*a = NULL;
	*b = NULL;
	init_stacks(a, argc, argv);
	print_list(*a);
	if (is_sorted(a))
	{
		free_stacks(a, b);
		return (0);
	}
	free_stacks(a, b);
	return (0);
}
