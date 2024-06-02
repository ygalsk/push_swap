/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:36:43 by dkremer           #+#    #+#             */
/*   Updated: 2024/06/02 03:52:23 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/include/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_list
{
	int				value;
	int				index;
	int				price;
	bool			a_med;
	bool			cheapest;
	struct s_list	*target;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

// Checking the Arguments

void				ft_check_args(int argc, char **argv);
bool				is_sorted(t_list **stack);
long				ft_atol(const char *str);

// Error and Free Functions

void				error(void);
void				free_list(char **str);
void				free_stack(t_list **stack);
void				free_stacks(t_list **a, t_list **b);
void				free_and_error(char **str);
void	check_error(int argc, char **str);

// Instructions

int					swap(t_list **stack);
int					sa(t_list **stack_a);
int					sb(t_list **stack_b);
int					ss(t_list **stack_a, t_list **stack_b);
int					rotate(t_list **stack);
int					ra(t_list **stack_a);
int					rb(t_list **stack_b);
int					rr(t_list **stack_a, t_list **stack_b);
int					reverse_rotate(t_list **stack);
int					rra(t_list **stack_a);
int					rrb(t_list **stack_b);
int					rrr(t_list **stack_a, t_list **stack_b);
int					push(t_list **stack_to, t_list **stack_from);
int					pa(t_list **stack_a, t_list **stack_b);
int					pb(t_list **stack_a, t_list **stack_b);

// List functions

t_list				*ft_lstnew(int value);
t_list				*ft_lstlast(t_list *head);
void				ft_lstadd_back(t_list **stack, t_list *new_node);
int					ft_listsize(t_list *head);
void				print_list(t_list *head);

// Sorting Functions

void				sort_3(t_list **a);
void				handle_5(t_list **a, t_list **b);
void				fast_sort(t_list **a, t_list **b);

// Sorting util functions

void				init_nodes_a(t_list *a, t_list *b);
void				init_nodes_b(t_list *a, t_list *b);
void				get_price_a(t_list *a, t_list *b);
void				get_price_b(t_list *a, t_list *b);
void				set_target_a(t_list *a, t_list *b);
void				set_target_b(t_list *a, t_list *b);
t_list				*cheapest(t_list *b);
t_list				*smallest(t_list *stack);
t_list				*biggest(t_list *stack);
void				init_index(t_list *stack);
void				move_a(t_list **a, t_list **b);
void				move_b(t_list **a, t_list **b);
void				finish_rotation_a(t_list **a, t_list **b, t_list *cheap);
void				finish_rotation_b(t_list **a, t_list **b, t_list *cheap);

#endif // !PUSH_SWAP_H
