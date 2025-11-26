/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahoumi <abahoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:46:57 by abahoumi          #+#    #+#             */
/*   Updated: 2025/11/26 11:47:59 by abahoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_highest(t_stack *stack)
{
	t_stack	*highest_node;

	if (!stack)
		return (NULL);
	highest_node = stack;
	stack = stack->next;
	while (stack)
	{
		if (stack->value > highest_node->value)
			highest_node = stack;
		stack = stack->next;
	}
	return (highest_node);
}

void	sort_three(t_stack **stack)
{
	t_stack	*highest_node;

	highest_node = find_highest(*stack);
	if (*stack == highest_node)
		ra(stack, 1);
	else if ((*stack)->next == highest_node)
		rra(stack, 1);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, 1);
}

static t_stack	*find_smallest(t_stack *stack)
{
	t_stack	*smallest_node;

	if (!stack)
		return (NULL);
	smallest_node = stack;
	stack = stack->next;
	while (stack)
	{
		if (stack->value < smallest_node->value)
			smallest_node = stack;
		stack = stack->next;
	}
	return (smallest_node);
}

void	sort_five(t_stack **a, t_stack **b)
{
	t_stack	*smallest_node;

	while (stack_size(*a) > 3)
	{
		smallest_node = find_smallest(*a);
		while (*a != smallest_node)
		{
			if (smallest_node == (*a)->next || smallest_node == (*a)->next->next)
				ra(a, 1);
			else
				rra(a, 1);
		}
		pb(a, b, 1);
	}
	sort_three(a);
	while (*b)
		pa(b, a, 1);
}
