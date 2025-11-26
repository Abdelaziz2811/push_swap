/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahoumi <abahoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 08:07:18 by abahoumi          #+#    #+#             */
/*   Updated: 2025/10/22 08:48:30 by abahoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(char const *s, char c)
{
	size_t	size;
	size_t	i;

	i = 0;
	size = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			size++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (size);
}

static void	free_strs(char **strs, size_t indx)
{
	while (indx--)
		free(strs[indx]);
	free(strs);
}

static char	**fill_strs(char **strs, char const *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			strs[j] = ft_substr(s, start, i - start);
			if (!strs[j++])
			{
				free_strs(strs, j);
				return (NULL);
			}
		}
		else
			i++;
	}
	strs[j] = NULL;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	size;

	if (!s)
		return (NULL);
	size = get_size(s, c);
	strs = malloc(sizeof(char *) * (size + 1));
	if (!strs)
		return (NULL);
	if (!fill_strs(strs, s, c))
		return (NULL);
	return (strs);
}
