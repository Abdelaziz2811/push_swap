/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahoumi <abahoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:46:04 by abahoumi          #+#    #+#             */
/*   Updated: 2025/11/26 11:47:06 by abahoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **sender, t_stack **receiver)
{
	t_stack	*node_to_push;

	if (!*sender)
		return ;
	node_to_push = *sender;
	*sender = (*sender)->next;
	if (*sender)
		(*sender)->prev = NULL;
	if (!*receiver)
	{
		*receiver = node_to_push;
		node_to_push->next = NULL;
		return ;
	}
	node_to_push->next = *receiver;
	node_to_push->next->prev = node_to_push;
	*receiver = node_to_push;
}

void	pa(t_stack **b, t_stack **a, int print)
{
	push(b, a);
	if (print)
		ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b, int print)
{
	push(a, b);
	if (print)
		ft_printf("pb\n");
}
