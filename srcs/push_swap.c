/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahoumi <abahoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 11:18:07 by abahoumi          #+#    #+#             */
/*   Updated: 2025/11/26 10:43:19 by abahoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	print_stack(t_stack *stack)
{
	if (!stack)
		return ;
	while (stack)
	{
		ft_printf("[%d] -> ", stack->value);
		stack = stack->next;
	}
	ft_printf("NULL\n");
}
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1 || (argc == 2 && !*argv[1]))
		return (0);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv = argv + 1;
	if (!parse_args(argv))
		return (ft_putendl_fd("Error", 2), 0);
	init_stack(&a, argv);
	if (!stack_sorted(a))
	{
		if (stack_size(a) == 2)
			sa(&a, 1);
		else if (stack_size(a) == 3)
			sort_three(&a);
		else if (stack_size(a) <= 5)
			sort_five(&a, &b);
	}
	print_stack(a);
	if (argc == 2)
		free_args(argv);
	free_stack(&a);
	return (0);
}
