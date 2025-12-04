/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahoumi <abahoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:09:09 by abahoumi          #+#    #+#             */
/*   Updated: 2025/12/04 18:18:51 by abahoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../ft_printf/includes/ft_printf.h"
#include "../gnl/get_next_line.h"

t_list	*process_operations(void);
void	execute_operations(t_list *operations, t_stack **a, t_stack **b);
void	free_list(t_list *operations);
