/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahoumi <abahoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:17:23 by abahoumi          #+#    #+#             */
/*   Updated: 2025/12/08 17:07:30 by abahoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	execute_operation(char *operation, size_t operation_len,
								t_stack **a, t_stack **b)
{
	if (!ft_strncmp(operation, "sa\n", operation_len))
		sa(a, 0);
	else if (!ft_strncmp(operation, "sb\n", operation_len))
		sb(b, 0);
	else if (!ft_strncmp(operation, "ss\n", operation_len))
		ss(a, b, 0);
	else if (!ft_strncmp(operation, "pa\n", operation_len))
		pa(b, a, 0);
	else if (!ft_strncmp(operation, "pb\n", operation_len))
		pb(a, b, 0);
	else if (!ft_strncmp(operation, "ra\n", operation_len))
		ra(a, 0);
	else if (!ft_strncmp(operation, "rb\n", operation_len))
		rb(b, 0);
	else if (!ft_strncmp(operation, "rr\n", operation_len))
		rr(a, b, 0);
	else if (!ft_strncmp(operation, "rra\n", operation_len))
		rra(a, 0);
	else if (!ft_strncmp(operation, "rrb\n", operation_len))
		rrb(b, 0);
	else if (!ft_strncmp(operation, "rrr\n", operation_len))
		rrr(a, b, 0);
}

void	execute_operations(t_list *operations, t_stack **a, t_stack **b)
{
	char	*operation;
	t_list	*to_free;

	to_free = operations;
	*b = NULL;
	while (operations)
	{
		operation = (char *)operations->content;
		execute_operation(operation, ft_strlen(operation), a, b);
		operations = operations->next;
	}
	free_list(to_free);
}
