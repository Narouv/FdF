/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:20:40 by rnauke            #+#    #+#             */
/*   Updated: 2022/05/27 23:39:48 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	cntr;

	if (!dst && !src)
		return (dst);
	cntr = 0;
	if ((src < dst) && (dst < src + len))
	{
		dst += len;
		src += len;
		while (len--)
			*(char *)--dst = *(char *)--src;
		return (dst);
	}
	while (len--)
	{
		*((char *)dst + cntr) = *((char *)src + cntr);
		cntr++;
	}
	return (dst);
}
