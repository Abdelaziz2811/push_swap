/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahoumi <abahoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:15:43 by abahoumi          #+#    #+#             */
/*   Updated: 2025/12/10 15:56:56 by abahoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

static int	is_number(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (0);
	while (s[i] && ft_isdigit(s[i]))
		i++;
	if (s[i])
		return (0);
	return (1);
}

int	valid_format(char **args)
{
	int		i;
	long	number;

	if (!args)
		return (0);
	i = 0;
	while (args[i])
	{
		if (!is_number(args[i]))
			return (0);
		if (ft_strlen(args[i] + get_leading_zeros_count(args[i])) > 11)
			return (0);
		number = ft_atol(args[i]);
		if (number > 2147483647 || number < -2147483648)
			return (0);
		i++;
	}
	return (!contains_duplicate(args));
}

void	free_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}
