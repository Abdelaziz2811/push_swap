/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahoumi <abahoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:08:41 by abahoumi          #+#    #+#             */
/*   Updated: 2025/12/06 10:28:58 by abahoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int argc, char **argv)
{
	char	**args;
	t_stack	*a;
	t_stack	*b;
	t_list	*operations;

	if (argc == 1)
		return (0);
	args = get_args(argv);
	if (!valid_format(args) || !*argv[1])
		return (free_args(args), ft_putendl_fd("Error", 2), 0);
	init_stack(&a, args);
	operations = process_operations();
	if (!operations)
		return (ft_putendl_fd("Error", 2), 0);
	execute_operations(operations, &a, &b);
	if (stack_sorted(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_args(args);
	free_stack(&a);
	return (0);
}
