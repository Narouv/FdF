/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:22:26 by rnauke            #+#    #+#             */
/*   Updated: 2022/06/01 03:27:05 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*alloc;

	if (count >= SIZE_MAX || size >= SIZE_MAX)
		return (NULL);
	alloc = malloc(count * size);
	if (!alloc)
		return (NULL);
	ft_bzero(alloc, count * size);
	return (alloc);
}
