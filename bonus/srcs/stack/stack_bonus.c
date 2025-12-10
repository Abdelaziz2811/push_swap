/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahoumi <abahoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 10:10:56 by abahoumi          #+#    #+#             */
/*   Updated: 2025/12/10 15:55:41 by abahoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	init_stack(t_stack **stack, char **args)
{
	int	i;

	i = 0;
	*stack = NULL;
	while (args[i])
		push_back(stack, ft_atoi(args[i++]));
}

void	free_stack(t_stack **stack)
{
	t_stack	*node_to_free;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		node_to_free = *stack;
		*stack = (*stack)->next;
		free(node_to_free);
	}
}

int	stack_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

size_t	stack_size(t_stack *stack)
{
	size_t	size;

	size = 0;
	if (!stack)
		return (size);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}
