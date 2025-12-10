/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_operations_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahoumi <abahoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:35:08 by abahoumi          #+#    #+#             */
/*   Updated: 2025/12/10 15:42:29 by abahoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	is_correct_format(char *operation)
{
	if (!ft_strncmp(operation, "sa\n", 3))
		return (1);
	else if (!ft_strncmp(operation, "sb\n", 3))
		return (1);
	else if (!ft_strncmp(operation, "ss\n", 3))
		return (1);
	else if (!ft_strncmp(operation, "pa\n", 3))
		return (1);
	else if (!ft_strncmp(operation, "pb\n", 3))
		return (1);
	else if (!ft_strncmp(operation, "ra\n", 3))
		return (1);
	else if (!ft_strncmp(operation, "rb\n", 3))
		return (1);
	else if (!ft_strncmp(operation, "rr\n", 3))
		return (1);
	else if (!ft_strncmp(operation, "rra\n", 4))
		return (1);
	else if (!ft_strncmp(operation, "rrb\n", 4))
		return (1);
	else if (!ft_strncmp(operation, "rrr\n", 4))
		return (1);
	else
		return (0);
}

void	free_list(t_list *operations)
{
	t_list	*node_to_free;

	while (operations)
	{
		node_to_free = operations;
		operations = operations->next;
		free(node_to_free->content);
		free(node_to_free);
	}
}

t_list	*process_operations(int *is_error)
{
	t_list	*operations;
	char	*line;

	operations = NULL;
	*is_error = 0;
	line = get_next_line(0);
	while (line)
	{
		if (!is_correct_format(line))
			return (*is_error = 1, free(line), free_list(operations), NULL);
		ft_lstadd_back(&operations, ft_lstnew((void *)ft_strdup(line)));
		free(line);
		line = get_next_line(0);
	}
	return (operations);
}
