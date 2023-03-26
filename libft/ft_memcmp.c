/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:22:02 by rnauke            #+#    #+#             */
/*   Updated: 2022/05/02 13:27:13 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		diff;
	size_t	cntr;

	diff = 0;
	cntr = 0;
	while (cntr < n && !diff)
	{
		diff = *(unsigned char *)(s1 + cntr) - *(unsigned char *)(s2 + cntr);
		cntr++;
	}
	return (diff);
}
