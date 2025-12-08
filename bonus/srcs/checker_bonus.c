/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahoumi <abahoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:08:41 by abahoumi          #+#    #+#             */
/*   Updated: 2025/12/08 18:18:59 by abahoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int argc, char **argv)
{
	char	**args;
	t_stack	*a;
	t_stack	*b;
	t_list	*operations;
	int		is_error;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	args = get_args(argv);
	if (!valid_format(args) || !*argv[1] || is_empty_or_whitespace(argv))
		return (free_args(args), ft_putendl_fd("Error", 2), 0);
	init_stack(&a, args);
	operations = process_operations(&is_error);
	if (!operations && is_error)
		return (free_memory(args, &a, &b), ft_putendl_fd("Error", 2), 0);
	execute_operations(operations, &a, &b);
	if (stack_sorted(a) && !stack_size(b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_memory(args, &a, &b);
	return (0);
}
