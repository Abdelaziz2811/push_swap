/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahoumi <abahoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:15:43 by abahoumi          #+#    #+#             */
/*   Updated: 2025/12/01 13:38:24 by abahoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*quote_args(char **argv)
{
	int		i;
	char	*args;
	char	*old_args;

	i = 1;
	args = ft_strdup("");
	if (!args)
		return (NULL);
	while (argv[i])
	{
		old_args = args;
		args = ft_strjoin(args, argv[i]);
		if (!args)
			return (free(old_args), NULL);
		free(old_args);
		old_args = args;
		args = ft_strjoin(args, " ");
		if (!args)
			return (free(old_args), NULL);
		free(old_args);
		i++;
	}
	return (args);
}

char	**get_args(char **argv)
{
	char	*quoted_args;
	char	**args;

	quoted_args = quote_args(argv);
	args = ft_split(quoted_args, ' ');
	free(quoted_args);
	return (args);
}

int	valid_format(char **args)
{
	int		i;
	int		j;
	char	*s_nbr;
	int		leading_zeros_count;

	i = 0;
	while (args[i])
	{
		j = 0;
		if (args[i][j] == '-' || args[i][j] == '+')
			j++;
		while (args[i][j] && ft_isdigit(args[i][j]))
			j++;
		if (args[i][j])
			return (0);
		leading_zeros_count = get_leading_zeros_count(args[i]);
		s_nbr = ft_itoa(ft_atoi(args[i]));
		if (ft_strlen(s_nbr) != ft_strlen(args[i] + leading_zeros_count))
			return (free(s_nbr), 0);
		free(s_nbr);
		i++;
	}
	return (!contains_duplicate(args));
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}
