/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:15:20 by rnauke            #+#    #+#             */
/*   Updated: 2022/05/28 17:29:05 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	cntr;

	cntr = 0;
	while (cntr < dstsize && cntr < ft_strlen(src))
	{
		if (cntr == dstsize - 1)
		{
			*(dst + cntr) = '\0';
			break ;
		}
		*(dst + cntr) = *(src + cntr);
		cntr++;
	}
	if (cntr == ft_strlen(src))
		*(dst + cntr) = '\0';
	return (ft_strlen(src));
}
