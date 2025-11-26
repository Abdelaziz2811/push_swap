/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahoumi <abahoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:45:55 by abahoumi          #+#    #+#             */
/*   Updated: 2025/11/25 11:51:20 by abahoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rrotate(t_stack **stack)
{
	t_stack	*node_to_rotate;

	if (!*stack || !(*stack)->next)
		return ;
	node_to_rotate = stack_last(*stack);
	(*stack)->prev = node_to_rotate;
	node_to_rotate->next = *stack;
	node_to_rotate->prev->next = NULL;
	node_to_rotate->prev = NULL;
	*stack = node_to_rotate;
}

void	rra(t_stack **a, int print)
{
	rrotate(a);
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_stack **b, int print)
{
	rrotate(b);
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b, int print)
{
	rra(a, 0);
	rrb(b, 0);
	if (print)
		ft_printf("rrr\n");
}
