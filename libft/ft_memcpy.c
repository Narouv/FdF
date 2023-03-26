/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:20:28 by rnauke            #+#    #+#             */
/*   Updated: 2022/05/28 17:28:12 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	cntr;

	cntr = 0;
	if (!dst && !src)
		return (dst);
	while (cntr < n)
	{
		*(unsigned char *)(dst + cntr) = *(unsigned char *)(src + cntr);
		cntr++;
	}
	return (dst);
}
