/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahoumi <abahoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:07:34 by abahoumi          #+#    #+#             */
/*   Updated: 2025/11/28 10:31:51 by abahoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

static void	rotate_both(t_stack **a, t_stack**b, t_stack *cheapest)
{
	while (*a != cheapest && *b != cheapest->target_node)
		rr(a, b, 1);
	current_index(*a);
	current_index(*b);
}

static void	rev_rotate_both(t_stack **a, t_stack**b, t_stack *cheapest)
{
	while (*a != cheapest && *b != cheapest->target_node)
		rrr(a, b, 1);
	current_index(*a);
	current_index(*b);
}

void	prep_for_push(t_stack **stack, t_stack *cheapest, char stack_name)
{
	while (*stack != cheapest)
	{
		if (stack_name == 'a')
		{
			if (cheapest->above_median)
				ra(stack, 1);
			else
				rra(stack, 1);
		}
		else if (stack_name == 'b')
		{
			if (cheapest->above_median)
				rb(stack, 1);
			else
				rrb(stack, 1);
		}
	}
}

void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(a, b, 1);
}
