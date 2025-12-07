/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahoumi <abahoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 11:18:27 by abahoumi          #+#    #+#             */
/*   Updated: 2025/12/07 14:02:55 by abahoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/includes/ft_printf.h"
# include <limits.h>

char	**get_args(char **argv);
int		valid_format(char **args);
int		contains_duplicate(char **args);
int		get_leading_zeros_count(char *arg);
void	free_args(char **args);
int		get_max(int a, int b);
int		is_empty_or_whitespace(char **args);

typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	int				above_median;
	int				cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void	init_stack(t_stack **stack, char **args);
t_stack	*stack_last(t_stack *stack);
void	push_back(t_stack **stack, int value);
void	free_stack(t_stack **stack);
int		stack_sorted(t_stack *stack);
size_t	stack_size(t_stack *stack);
void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	ss(t_stack **a, t_stack **b, int print);
void	pa(t_stack **b, t_stack **a, int print);
void	pb(t_stack **a, t_stack **b, int print);
void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rr(t_stack **a, t_stack **b, int print);
void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b, int print);
void	sort_three(t_stack **stack);
void	sort_five(t_stack **a, t_stack **b);
t_stack	*find_highest(t_stack *stack);
t_stack	*find_smallest(t_stack *stack);
void	init_nodes_a(t_stack *a, t_stack *b);
void	current_index(t_stack *stack);
void	move_a_to_b(t_stack **a, t_stack **b);
void	init_nodes_b(t_stack *a, t_stack *b);
void	prep_for_push(t_stack **stack, t_stack *cheapest, char stack_name);
void	sort_stacks(t_stack **a, t_stack **b);

#endif