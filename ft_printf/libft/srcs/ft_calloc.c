/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahoumi <abahoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:43:27 by abahoumi          #+#    #+#             */
/*   Updated: 2025/10/15 14:57:15 by abahoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem_area;

	mem_area = malloc(nmemb * size);
	if (!mem_area)
		return (NULL);
	ft_bzero(mem_area, nmemb * size);
	return (mem_area);
}
