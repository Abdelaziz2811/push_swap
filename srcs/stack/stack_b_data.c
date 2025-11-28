/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahoumi <abahoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:42:09 by abahoumi          #+#    #+#             */
/*   Updated: 2025/11/28 10:15:53 by abahoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*target_node;
	t_stack	*current_a;
	int		current_target;

	while (b)
	{
		current_a = a;
		current_target = INT_MAX;
		while (current_a)
		{
			if (b->value < current_a->value
				&& current_a->value < current_target)
			{
				current_target = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (current_target == INT_MAX)
			b->target_node = find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	init_nodes_b(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}
