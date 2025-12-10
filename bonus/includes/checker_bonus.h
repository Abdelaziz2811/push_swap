/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahoumi <abahoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:09:09 by abahoumi          #+#    #+#             */
/*   Updated: 2025/12/10 16:59:51 by abahoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf/includes/ft_printf.h"
#include "../gnl/get_next_line_bonus.h"

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
t_list	*process_operations(int *is_error);
void	execute_operations(t_list *operations, t_stack **a, t_stack **b);
void	free_list(t_list *operations);
void	free_memory(char **args, t_stack **a, t_stack **b);
