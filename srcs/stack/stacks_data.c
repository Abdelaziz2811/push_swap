/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahoumi <abahoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:42:09 by abahoumi          #+#    #+#             */
/*   Updated: 2025/11/27 12:08:02 by abahoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack *stack)
{
	int	index;
	int	median;

	if (!stack)
		return ;
	index = 0;
	median = stack_size(stack) / 2;
	while (stack)
	{
		stack->index = index;
		if (index <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		index++;
		stack = stack->next;
	}
}

static void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack	*target_node;
	t_stack	*current_b;
	int		current_target;

	while (a)
	{
		current_b = b;
		current_target = -2147483648;
		while (current_b)
		{
			if (a->value > current_b->value
				&& current_b->value > current_target)
			{
				current_target = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (current_target == -2147483648)
			target_node = find_highest(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void	set_push_cost_a(t_stack *a, t_stack *b)
{
	int	a_size;
	int	b_size;
	
	a_size = stack_size(a);
	b_size = stack_size(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = a_size - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += b_size - (a->target_node->index);
		a = a->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	int		cheapest_value;
	t_stack	*cheapest_node;
	
	cheapest_value = 2147483647;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
}

void	init_nodes_a(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	set_push_cost_a(a, b);
	set_cheapest(a);
}
