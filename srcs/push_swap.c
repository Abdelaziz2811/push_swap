/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahoumi <abahoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 11:18:07 by abahoumi          #+#    #+#             */
/*   Updated: 2025/11/25 14:36:25 by abahoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**args;
	t_stack	*a;

	if (argc == 1 || (argc == 2 && !*argv[1]))
		return (0);
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	if (!parse_args(args))
		return (ft_putendl_fd("Error", 2), 0);
	init_stack(&a, args);
	if (!stack_sorted(a))
	{
		if (stack_size(a) == 2)
			sa(&a, 1);
	}
	if (argc == 2)
		free_args(args);
	free_stack(&a);
	return (0);
}
