/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:36:43 by dkremer           #+#    #+#             */
/*   Updated: 2024/04/20 16:32:43 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/include/libft.h"
# include <stdbool.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

bool				is_sorted(t_list **stack);
void				free_list(char **str);
void				error(void);
void				free_stack(t_list **stack);
void				free_stacks(t_list **a, t_list **b);
t_list				*ft_lstnew(int value);
void				ft_lstadd_front(t_list **stack, t_list *new);
t_list				*ft_lstlast(t_list *head);
void				ft_lstadd_back(t_list **stack, t_list *new);
int					ft_listsize(t_list *head);
void				print_list(t_list *head);
//int  ft_isnum(char *num);
//int  ft_contains(int num, char **args, int i);
void	ft_check_args(int argc, char **argv);
void    lst_addback(t_list **root, int value);
int swap(t_list **stack);
int sa(t_list **stack_a);
int sb(t_list **stack_b);
int ss(t_list **stack_a, t_list **stack_b);
int rotate(t_list **stack);
int ra(t_list **stack_a);
int rb(t_list **stack_b);
int rr(t_list **stack_a, t_list **stack_b);
int reverse_rotate(t_list **stack);
int rra(t_list **stack_a);
int rrb(t_list **stack_b);
int rrr(t_list **stack_a, t_list **stack_b);
int push(t_list **stack_to, t_list **stack_from);
int pa(t_list **stack_a, t_list **stack_b);
int pb(t_list **stack_a, t_list **stack_b);
int	get_distance(t_list **stack, int index);
void	stack_index(t_list **stack);
void    simple_sort(t_list **a, t_list **b);

#endif // !PUSH_SWAP_H
