/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahoumi <abahoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:45:59 by abahoumi          #+#    #+#             */
/*   Updated: 2025/11/25 14:38:40 by abahoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*last_node;
	t_stack	*node_to_rotate;

	if (!*stack || !(*stack)->next)
		return ;
	node_to_rotate = *stack;
	last_node = stack_last(*stack);
	last_node->next = node_to_rotate;
	node_to_rotate->prev = last_node;
	*stack = node_to_rotate->next;
	(*stack)->prev = NULL;
	node_to_rotate->next = NULL;
}

void	ra(t_stack **a, int print)
{
	rotate(a);
	if (print)
		ft_printf("ra\n");
}

void	rb(t_stack **b, int print)
{
	rotate(b);
	if (print)
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b, int print)
{
	ra(a, 0);
	rb(b, 0);
	if (print)
		ft_printf("rr\n");
}
