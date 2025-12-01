/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahoumi <abahoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 11:18:07 by abahoumi          #+#    #+#             */
/*   Updated: 2025/12/01 14:48:03 by abahoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**args;
	t_stack	*a;
	t_stack	*b;

	if (argc == 1 || !*argv[1])
		return (0);
	args = get_args(argv);
	if (!valid_format(args))
		return (ft_putendl_fd("Error", 2), 0);
	init_stack(&a, args);
	if (!stack_sorted(a))
	{
		if (stack_size(a) == 2)
			sa(&a, 1);
		else if (stack_size(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_args(args);
	free_stack(&a);
	return (0);
}
