/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahoumi <abahoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:56:32 by abahoumi          #+#    #+#             */
/*   Updated: 2025/11/28 11:48:59 by abahoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	smallest_to_top(t_stack **a)
{
	t_stack	*smallest_node;

	smallest_node = find_smallest(*a);
	while (*a != smallest_node)
	{
		if (smallest_node->above_median)
			ra(a, 1);
		else
			rra(a, 1);
	}
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	int	a_size;

	a_size = stack_size(*a);
	while (a_size > 3 && !stack_sorted(*a) && stack_size(*b) < 2)
	{
		pb(a, b, 1);
		a_size--;
	}
	while (a_size > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
		a_size--;
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		prep_for_push(a, (*b)->target_node, 'a');
		pa(b, a, 1);
	}
	current_index(*a);
	smallest_to_top(a);
}
