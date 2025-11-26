/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahoumi <abahoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 10:40:45 by abahoumi          #+#    #+#             */
/*   Updated: 2025/11/25 11:58:22 by abahoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*stack_new(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->prev = NULL;
	node->value = value;
	node->next = NULL;
	return (node);
}

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	push_back(t_stack **stack, int value)
{
	t_stack	*last_node;
	t_stack	*new_node;

	if (!stack)
		return ;
	new_node = stack_new(value);
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	last_node = stack_last(*stack);
	last_node->next = new_node;
	new_node->prev = last_node;
}
