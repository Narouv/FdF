/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:15:57 by rnauke            #+#    #+#             */
/*   Updated: 2022/06/01 01:59:50 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	cntr;
	int		diff;

	diff = 0;
	cntr = 0;
	while (cntr < n && !diff)
	{
		if (!*(s1 + cntr) && !*(s2 + cntr))
			break ;
		if (!*(s1 + cntr))
			diff -= *(unsigned char *)(s2 + cntr);
		if (!*(s1 + cntr))
			diff += *(unsigned char *)(s1 + cntr);
		diff = *(unsigned char *)(s1 + cntr) - *(unsigned char *)(s2 + cntr);
		cntr++;
	}
	return (diff);
}
