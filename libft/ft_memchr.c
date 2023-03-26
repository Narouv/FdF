/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:21:19 by rnauke            #+#    #+#             */
/*   Updated: 2022/05/27 01:48:27 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	cntr;

	cntr = 0;
	while (cntr < n)
	{
		if (*(unsigned char *)(s + cntr) == (unsigned char)c)
		{
			return ((void *)s + cntr);
		}
		cntr++;
	}
	return (NULL);
}
